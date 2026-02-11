#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e6 + 7;

void solve ()
{   
    int n, m; cin >> n >> m;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <int> dp(10000);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= min(j, v[i]); k++) {
                dp[j] = (dp[j] + dp[j - k]) % mod;
            }
        }
    }

    cout << dp[m] << '\n';
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