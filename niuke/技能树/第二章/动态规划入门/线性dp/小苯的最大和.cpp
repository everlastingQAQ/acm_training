#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    if (n >= 1) dp[1] = v[1];
    if (n >= 2) dp[2] = max(dp[1] + v[2], 0LL);
    if (n >= 3) dp[3] = max({dp[3 - 1] + v[3], dp[1], 0LL});

    for (int i = 4; i <= n; i++) {
        dp[i] = max({dp[i - 1] + v[i], dp[i - 2], dp[i - 3]});
    }

    cout << dp[n] << '\n';
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}