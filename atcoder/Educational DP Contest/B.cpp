#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, k; cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <int> dp(n + 1, 1e11);
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= max(1LL, i - k); j--) {
            dp[i] = min(dp[i], dp[j] + abs(v[i] - v[j]));
        }
    }

    cout << dp[n] << '\n';
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