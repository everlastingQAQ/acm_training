#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int mod = 1e9 + 7;

void solve ()
{
    int n; cin >> n;
    vector <array<int, 2> > dp(n + 1);
    dp[1][0] = 0, dp[1][1] = 1;
    if (n >= 2) dp[2][0] = 1, dp[2][1] = 0; 

    for (int i = 3; i <= n; i++) {
        dp[i][0] = (dp[i - 2][1] + dp[i - 2][0]) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 2][1]) % mod;
    }

    cout << (dp[n][0] + dp[n][1]) % mod << '\n';
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

// dp[i][0] = dp[i - 2][1] + dp[i - 4][1] + dp[i - 6][0] + ...
// dp[i - 2][0] = dp[i - 4][1] + dp[i - 6][0] + ...
// dp[i][0] = dp[i - 2][1] + dp[i - 2][0]

// dp[i][1] = dp[i - 1][0] + dp[i - 3][0] + dp[i - 5][0] + ...
// dp[i - 2][1] = dp[i - 3][0] + dp[i - 5][0] + ...
// dp[i][1] = dp[i - 1][0] + dp[i - 2][1]; 