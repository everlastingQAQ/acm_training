#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    i64 w;
    cin >> n >> m >> w;
    vector <vector <i64> > v(n + 1, vector <i64> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    vector <vector <vector <i64> > > dp(n + 1, vector <vector <i64> > (m + 1, vector <i64> (m, 1e18)));
    vector <vector <i64> > mn(n + 1, vector <i64> (m + 1, 1e18));
    
    for (int k = 0; k < m; k++) {
        dp[1][1][k] = 1 * w * k + v[1][(1 + k - 1) % m + 1];
        mn[1][1] = min(mn[1][1], dp[1][1][k]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            for (int k = 0; k < m; k++) {
                dp[i][j][k] = min(dp[i][j - 1][k], mn[i - 1][j] + w * k) + v[i][(j + k - 1) % m + 1];
                mn[i][j] = min(mn[i][j], dp[i][j][k]);
            }
        }
    }

    cout << mn[n][m] << '\n';
}

int main ()
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