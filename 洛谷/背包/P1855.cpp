#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    vector <vector <int> > dp(m + 1, vector <int> (t + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i][0]; j--) {
            for (int k = t; k >= v[i][1]; k--) {
                dp[j][k] = max(dp[j - v[i][0]][k - v[i][1]] + 1, dp[j][k]);
            }
        }
    }

    cout << dp[m][t] << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   