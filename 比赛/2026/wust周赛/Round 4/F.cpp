#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <vector <i64> > dp(n + 1, vector <i64> (6 * m, -1e18));
    dp[0][0] = 0;

    for (int i = 1; i <= 6 * m && i <= n; i++) {
        if (i <= 6) dp[i][1] = v[i];
        for (int j = i - 1; j >= i - 6 && j >= 0; j--) {
            for (int k = max(1, j / 6); k <= j; k++) {
                dp[i][k + 1] = max(dp[i][k + 1], dp[j][k] + v[i]); 
            }
        }
    }

    i64 ans = -1e18;
    for (int i = m; i <= n && i <= m * 6; i++) {
        ans = max(ans, dp[i][m]);
    }
    cout << ans << '\n';
}

int main ()
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