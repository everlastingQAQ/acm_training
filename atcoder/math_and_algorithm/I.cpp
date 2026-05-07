#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, s;
    cin >> n >> s;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    vector <vector <int> > dp(n + 1, vector <int> (s + 1, 0));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (dp[i - 1][j]) dp[i][j] = true;
            if (j >= v[i] && dp[i - 1][j - v[i]]) {
                dp[i][j] = true;
            }
        }
    }
    cout << (dp[n][s] ? "Yes\n" : "No\n");
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