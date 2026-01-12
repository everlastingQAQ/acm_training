#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    // ranges::sort(v | views::drop(1));
    sort(v.begin() + 1, v.end());

    vector <int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i - v[i] >= 0) dp[i] = max(dp[i - 1], dp[i - v[i]] + 1);
        else dp[i] = dp[i - 1];
    }

    if (n - v[n] >= 0) {
        cout << dp[n - v[n]] + 1 << '\n';
    }else {
        cout << -1 << '\n';
    }
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}