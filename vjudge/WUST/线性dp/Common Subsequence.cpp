#include <bits/stdc++.h>
using namespace std;
#define int long long

string s, t;

void solve ()
{   
    int n = s.size(), m = t.size();
    vector <vector <int> > dp(n + 1, vector <int> (m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i][j]});
        }
    }

    cout << dp[n][m] << '\n';
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    // while (_--) {
    //     solve();
    // }
    while (cin >> s >> t) {
        solve();
    }
    return 0;
} 