#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m; cin >> n >> m;
    vector <int> a(m + 1), b(n);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ranges::sort(a | views::drop(1));

    vector <int> dp(n + 1, -1e11);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - a[j] < 0) break;
            dp[i] = max(dp[i], b[i - a[j]] + dp[i - a[j]]);
        }
    }

    int ans = dp[n];
    for (int i = n - 1; i >= max(1LL, n - a[m]); i--) {
        ans = max(ans, dp[i] + b[i]);
    }

    cout << ans << '\n';
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