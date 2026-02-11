#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; 
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <int> dp(n + 1, 1e11);
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= min(v[i] + i, n); j++) {
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }

    cout << dp[n] << '\n'; 
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