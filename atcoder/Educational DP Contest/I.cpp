#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int n; cin >> n;
    vector <long double> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector <vector <long double> > dp(n + 1, vector <long double> (n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] * (1 - v[i]);
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] * v[i] + dp[i - 1][j] * (1 - v[i]);
        }
    }

    long double ans = 0;
    for (int i = 1; i <= n; i++) {
        if (n - i < i) {
            ans += dp[n][i];
        }
    }

    cout << fixed << setprecision(9) << ans << '\n';
}   
    
int32_t main ()
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