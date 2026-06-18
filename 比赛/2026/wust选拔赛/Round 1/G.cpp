#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void solve ()
{
    int n, m;
    cin >> n >> m;
    using arr2 = array <int, 2>;
    vector <vector <arr2> > e(n);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    int s;
    cin >> s;
    vector <int> a(s + 1);
    for (int i = 1; i <= s; i++) {
        cin >> a[i];
    }

    auto cal = [&] (int st) -> vector <int> {
        priority_queue <arr2, vector <arr2>, greater<arr2> > pq;
        pq.push({0, st});
        vector <int> dis(n, INF);
        dis[st] = 0;

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

    vector <vector <int> > dis(s + 1);
    for (int i = 0; i <= s; i++) {
        dis[i] = cal(a[i]);
    }

    vector <vector <int> > dp(1 << s, vector <int> (s + 1, INF));
    for (int i = 1; i <= s; i++) {
        dp[1 << (i - 1)][i] = dis[0][a[i]];
    }

    for (int mask = 0; mask < (1 << s); mask++) {
        for (int i = 1; i <= s; i++) {
            if (dp[mask][i] == INF) continue;
            for (int j = 1; j <= s; j++) {
                if (mask >> (j - 1) & 1) continue;
                int nmask = mask | (1LL << (j - 1));
                dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + dis[i][a[j]]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= s; i++) {
        ans = min(ans, dp[(1 << s) - 1][i] + dis[i][0]);
    }

    cout << ans << '\n';
}

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}