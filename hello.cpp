#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> a(n + 1);
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    vector <int> dp(mx + 1);

    for (int i = 2; i <= mx; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                dp[i] = min(dp[i], dp[j] + dp[i / j] + 1);
            }
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) { 
        ans += dp[a[i]];
    }
    cout << ans << '\n';
}

int main ()
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