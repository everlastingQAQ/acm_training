#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, a, b, c; cin >> n >> a >> b >> c;
    string s; cin >> s; s = ' ' + s;

    vector <int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (i >= 3 && s.substr(i - 3, 4) == "nico") {
            dp[i] = max(dp[i - 3] + a, dp[i]);
        } 
        if (i >= 5 && s.substr(i - 5, 6) == "niconi") {
            dp[i] = max(dp[i - 5] + b, dp[i]);
        }
        if (i >= 9 && s.substr(i - 9, 10) == "niconiconi") {
            dp[i] = max(dp[i - 9] + c, dp[i]);
        }
    }

    cout << dp[n] << '\n';
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