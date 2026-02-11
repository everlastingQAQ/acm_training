#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n;
    cin >> n;
    vector <int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            dp[i] = dp[i - 1] + 1;
        }else {
            dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
        }
    }
    
    cout << dp[n] - 1 << '\n';
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