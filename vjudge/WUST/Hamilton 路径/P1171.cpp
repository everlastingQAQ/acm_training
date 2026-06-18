#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void solve ()
{
    int n;
    cin >> n;
    using arr2 = array <int, 2>;
    vector <vector <int> > dis(n, vector <int> (n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            dis[i][j] = w;
        }
    }

    vector <vector <int> > dp((1 << n), vector <int> (n, INF));
    dp[1][0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (dp[mask][i] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (mask >> j & 1) continue;
                int nmask = mask | (1LL << j);
                dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + dis[i][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i] + dis[i][0]);
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