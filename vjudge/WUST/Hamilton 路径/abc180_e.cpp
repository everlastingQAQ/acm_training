#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void solve ()
{
    int n;
    cin >> n;
    using arr3 = array <int, 3>;
    vector <arr3> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }

    auto cal = [&] (int i, int j) -> int {
        int res = llabs(p[i][0] - p[j][0]) + llabs(p[i][1] - p[j][1]) + max(0LL, p[j][2] - p[i][2]);
        return res;
    };

    vector <vector <int> > dp(1LL << n, vector <int> (n, INF));
    dp[1][0] = 0;

    for (int mask = 0; mask < (1LL << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (dp[mask][i] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (mask >> j & 1) continue;
                int nmask = mask | (1LL << j);
                dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + cal(i, j));
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1LL << n) - 1][i] + cal(i, 0));
    }
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