#include <bits/stdc++.h>
using namespace std;
#define int long long

int m, n;

void solve ()
{   
    vector <int> v(n + 1), dp(n + 1), mx(n + 1);
    for (int i = 1; i <= n; i++) {  
        cin >> v[i];
    }
    int ans = -1e17;

    for (int i = 1; i <= m; i++) {
        ans = -1e17;
        for (int j = i; j <= n; j++) {
            dp[j] = max(dp[j - 1], mx[j - 1]) + v[j];
            mx[j - 1] = ans;
            ans = max(ans, dp[j]);
        }
    }

    cout << ans << '\n';
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int _ = 1;
    // cin >> _;
    // while (_--) {
    //     solve();
    // }
    while (cin >> m >> n) {
        solve();
    }
    return 0;
} 