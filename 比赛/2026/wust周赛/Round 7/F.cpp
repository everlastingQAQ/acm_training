#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector <vector <vector <int> > > dp(n + 1, vector <vector <int> > (4 + 1, vector <int>(2 + 1, 1e18)));
    dp[1][0][0] = (s[1] == '1');
    dp[1][0][1] = (s[1] == '0');

    for (int i = 2; i <= n; i++) {
        int t = s[i] - '0';
        
        dp[i][0][t] = dp[i - 1][0][t];
        dp[i][1][t] = dp[i - 1][1][t];
        dp[i][2][t] = dp[i - 1][2][t];
        dp[i][3][t] = dp[i - 1][3][t];
        
        dp[i][1][t] = min(dp[i][1][t], dp[i - 1][0][t ^ 1]);
        dp[i][2][t] = min(dp[i][2][t], dp[i - 1][1][t ^ 1]);
        dp[i][3][t] = min(dp[i][3][t], dp[i - 1][2][t ^ 1]);

        dp[i][0][t ^ 1] = dp[i - 1][0][t ^ 1] + 1;
        dp[i][1][t ^ 1] = dp[i - 1][1][t ^ 1] + 1;
        dp[i][2][t ^ 1] = dp[i - 1][2][t ^ 1] + 1;
        dp[i][3][t ^ 1] = dp[i - 1][3][t ^ 1] + 1;

        dp[i][1][t ^ 1] = min(dp[i][1][t ^ 1], dp[i - 1][0][t] + 1);
        dp[i][2][t ^ 1] = min(dp[i][2][t ^ 1], dp[i - 1][1][t] + 1);
        dp[i][3][t ^ 1] = min(dp[i][3][t ^ 1], dp[i - 1][2][t] + 1);
    }

    cout << min(dp[n][3][1], dp[n][3][0]) << '\n';
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