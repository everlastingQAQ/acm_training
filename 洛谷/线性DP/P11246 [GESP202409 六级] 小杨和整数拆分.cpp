#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; cin >> n;
    vector <int> dp(n + 1);
    ranges::iota(dp, 0LL);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
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