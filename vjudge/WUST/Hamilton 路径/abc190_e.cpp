#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void solve ()
{
    int n, m;
    cin >> n >> m;
    using arr2 = array <int, 2>;
    vector <vector <arr2> > e(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, 1});
        e[v].push_back({u, 1});
    }

    int k;
    cin >> k;
    vector <int> a(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    vector <vector <int> > dis(k + 1);
    auto cal = [&] (int st) -> vector <int> {
        priority_queue <arr2, vector <arr2>, greater <arr2> > pq;
        vector <int> dis(n + 1, INF);
        dis[st] = 0;
        pq.push({0, st});
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            if (dist > dis[u]) continue;
            for (auto [v, w] : e[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis;
    };

    for (int i = 1; i <= k; i++) {
        dis[i] = cal(a[i]);
    }

    vector <vector <int> > dp(1LL << (k + 1), vector <int> (k + 1, INF));
    for (int i = 1; i <= k; i++) {
        dp[1LL << i][i] = 0;
    }

    for (int mask = 0; mask < (1LL << (k + 1)); mask++) {
        for (int i = 1; i <= k; i++) {
            if (dp[mask][i] == INF) continue;
            for (int j = 1; j <= k; j++) {
                if (mask >> j & 1) continue;
                int nmask = mask | (1LL << j);
                dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + dis[i][a[j]]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= k; i++) {
        ans = min(ans, dp[(1LL << (k + 1)) - 2][i]);
    }

    if (ans == INF) cout << -1;
    else cout << ans + 1;
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