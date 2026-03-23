#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 1000000007;

void solve ()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector <array <i64, 2> > dp(n + 1);
    dp[0][0] = 1, dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(k, i); j++) {
            if (j < d) {
                dp[i][0] = (dp[i][0] + dp[i - j][0]) % mod;
            }
            dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
            if (j >= d) {
                dp[i][1] = (dp[i][1] + dp[i - j][0]) % mod;
            }
        }
    }
    cout << dp[n][1] << '\n';
}   
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 