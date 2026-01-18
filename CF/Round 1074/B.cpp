#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    int mx = ranges::max(v | views::drop(1));
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == mx) {
            pos = i;
            break;
        }
    }

    swap(v[1], v[pos]);

    vector <int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1], v[i]);
        // cout << dp[i] << ' ';
    }

    cout << accumulate(dp.begin() + 1, dp.end(), 0LL) << '\n';
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}