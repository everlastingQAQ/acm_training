#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <i64> a(n + 1), b(n + 1);
    i64 sum = 0;
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if (sum >= k) {
            pos = i;
            sum = -1e18;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector <array <i64, 2> > dp(n + 1);
    dp[1][0] = a[1];
    dp[1][1] = 0;
    bool ok = false;    

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i];
        if (dp[i - 1][1] > k) {
            dp[i][0] = max(dp[i][0], dp[i - 1][1] - k + a[i]);
        }
        if (i == pos + 1) {
            dp[i][1] = dp[i - 1][0] - k + b[i];
            ok = true;
        }
        if (ok) {
            dp[i][1] = max(dp[i][1], dp[i - 1][1] + b[i]);
            if (dp[i - 1][0] > k) {
                dp[i][1] = max(dp[i][1], dp[i - 1][0] - k + b[i]);
            }
        }
        // cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
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