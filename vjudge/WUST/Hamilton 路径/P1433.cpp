#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void solve ()
{
    int n;
    cin >> n;
    using arr2 = array <double, 2>;
    vector <arr2> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    auto cal = [&] (double i, double j) -> double {
        double res = (p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]);
        return sqrtl(res);
    };

    vector <vector <double> > dp(1LL << (n + 1), vector <double> (n + 1, INF));
    dp[0][0] = 0;

    for (int mask = 0; mask < (1LL << (n + 1)); mask++) {
        for (int i = 0; i <= n; i++) {
            if (dp[mask][i] == INF) continue;
            for (int j = 0; j <= n; j++) {
                if (mask >> j & 1) continue;
                int nmask = mask | (1LL << j);
                dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + cal(i, j));
            }
        }
    }

    double ans = INF;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, dp[(1 << (n + 1)) - 1][i]);
    }
    cout << fixed << setprecision(2);
    cout << ans << '\n';
}

int32_t main ()
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