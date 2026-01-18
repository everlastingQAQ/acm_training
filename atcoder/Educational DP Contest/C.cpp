#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <array<int, 3> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    vector <array<int, 3>> dp(n + 1);
    dp[1][0] = v[1][0], dp[1][1] = v[1][1], dp[1][2] = v[1][2];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1] + v[i][0], dp[i - 1][2] + v[i][0]);
        dp[i][1] = max(dp[i - 1][0] + v[i][1], dp[i - 1][2] + v[i][1]);
        dp[i][2] = max(dp[i - 1][0] + v[i][2], dp[i - 1][1] + v[i][2]);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
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