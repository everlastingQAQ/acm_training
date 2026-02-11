#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 100003;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> dp(n + 1);
    dp[1] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= max(i - k, 1LL); j--) {
            dp[i] = (dp[i] + dp[j]) % mod;
        }
        if (i + k > n) {
            ans = (ans + dp[i]) % mod;
        }
    }
    cout << ans << '\n';
}   
    
int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int _ = 1;
    // cin >> _;
    while (_--)     {
        solve();
    }
    return 0;
} 

/*
  /\_/\
 (= ._.)
 / >  \>
*/