#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int m, n;
    cin >> m >> n;
    vector <int> a(n + 1), b(n + 1), c(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        mx += c[i];
    }
    vector <vector <int> > dp(m + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = mx; j >= b[i]; j--) {
            for (int k = m; k >= a[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - b[i]][k - a[i]] + c[i]);
            }
        }
    }
    cout << dp[mx][m] << '\n';
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