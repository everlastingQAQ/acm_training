#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;

const int mod = 2000120420010122;

void solve ()
{
    vector <int> dp(4);
    for (auto c : s) {
        if (c == 'c' || c == 'C') {
            dp[0] = (dp[0] + 1) % mod;
            dp[3] = (dp[3] + dp[2]) % mod;
        }else if (c == 'w' || c == 'W') {
            dp[1] = (dp[0] + dp[1]) % mod;
        }else if (c == 'b' || c == 'B') {
            dp[2] = (dp[1] + dp[2]) % mod;
        }
    }
    cout << dp[3] << '\n';
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
    while (cin >> s) {
        solve();
    }
    return 0;
} 