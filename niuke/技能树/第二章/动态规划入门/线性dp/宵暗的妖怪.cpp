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
    
    for (int i = 3; i <= n; i++) {
        dp[i] = max(v[i - 1] + dp[i - 3], dp[i - 1]);
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " \n"[i == n];
    }

    cout << dp[n] << '\n';
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