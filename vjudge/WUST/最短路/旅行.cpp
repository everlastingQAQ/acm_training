#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <array <int, 2> > > e(n + 1);
    vector <int> ind(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
        ind[u]++;
        ind[v]++;
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        vector <int> dis(n + 1, 1e9);
        priority_queue <array <int, 2>, vector <array <int, 2> >, greater<array <int, 2> > > pq;
        dis[i] = 0;
        pq.push({0, i});
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            if (dist != dis[u]) continue;
            for (auto [v, w] : e[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        int mx1 = 0;
        int pos = -1;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (j == i || dis[j] == 1e9) continue;
            cnt++;
            if (mx1 < dis[j]) {
                mx1 = dis[j];
                pos = j;
            }
        }
        if (cnt < 2) {
            continue;
        }
        int mx2 = 0;
        for (int j = 1; j <= n; j++) {
            if (j == i || j == pos) continue;
            if (dis[j] == 1e9) continue;
            mx2 = max(dis[j], mx2);
        }
        ans = max(mx1 + mx2, ans);
    }
    cout << ans << '\n';
}

int main ()
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