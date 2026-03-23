#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 1000000007;

void solve ()
{
    int t, k;
    cin >> t >> k;
    int mx = 0;
    vector <array <int, 2> > ans(t + 1);
    for (int i = 1; i <= t; i++) {
        cin >> ans[i][0] >> ans[i][1];
        mx = max(mx, ans[i][1]);
    }
    vector <i64> dp(mx + 1);
    dp[0] = 1;
    for (int i = 1; i <= mx; i++) {
        if (i >= k) dp[i] = (dp[i] + dp[i - k]) % mod;
        dp[i] = ((dp[i] + dp[i - 1])) % mod;
    }

    vector <i64> pre(mx + 1);
    for (int i = 1; i <= mx; i++) {
        pre[i] = (pre[i - 1] + dp[i]) % mod;
    }

    for (int i = 1; i <= t; i++) {
        i64 cur = (pre[ans[i][1]] - pre[ans[i][0] - 1] + mod) % mod;
        cout << cur << '\n';
    }
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