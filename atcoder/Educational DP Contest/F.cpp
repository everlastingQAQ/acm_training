#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t;
    vector <vector <int> > dp(n + 1, vector <int> (m + 1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    string ans;
    int x = n, y = m;
    while (x > 0 && y > 0) {
        if (s[x] == t[y]) {
            ans.push_back(s[x]);
            x--, y--;
        }else if (dp[x - 1][y] > dp[x][y - 1]) {
            x--;
        }else {
            y--;
        }
    }
    ranges::reverse(ans);
    cout << ans << '\n';
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