#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int mod = 1e9 + 7;

void solve ()
{
    int n, m; cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > dp(n + 1, vector <int> (m + 1));
    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (i == 1) {
                if (v[i][j] == '#') dp[i][j] = 0;
                else dp[i][j] = dp[i][j - 1];
                continue;
            }else if (j == 1) {
                if (v[i][j] == '#') dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j];
                continue;
            }

            if (v[i][j] == '#') dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }

    cout << dp[n][m] % mod << '\n';
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