#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <vector <char> > v(n + 1, vector <char> (n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > dp(n + 1, vector <int> (n + 1, 0));
    for (int i = 1; i <= n; i++) {
        vector <int> s(n + 1, 0);
        s[n] = dp[i - 1][n];
        for (int j = n - 1; j >= 0; j--) {
            s[j] = min(s[j + 1], dp[i - 1][j]);
        }

        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (v[i][j] == '.') cnt++;
        }
        dp[i][0] = cnt + s[0];
        for (int j = 1; j <= n; j++) {
            if (v[i][j] == '.') cnt--;
            else cnt++;
            dp[i][j] = cnt + s[j];
        }
    }

    int ans = 1e16;
    for (int i = 0; i <= n; i++) {
        ans = min(dp[n][i], ans);
    }

    cout << ans << '\n';
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