#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector <vector <array <int, 2> > > e(n + 1e5 + 10);
    int cur = n + 1;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vector <int> id(c + 1);
        for (int j = 1; j <= c; j++) {
            int u;
            cin >> u;
            id[j] = cur++;
            e[u].push_back({id[j], a});
            e[id[j]].push_back({u, 0});
            if (j != 1) {
                e[id[j]].push_back({id[j - 1], b});
                e[id[j - 1]].push_back({id[j], b});
            }
        }
    }

    vector <int> dis(cur + 1, 1e18);
    priority_queue <array <int, 2>, vector <array <int, 2> >, greater <array <int, 2> > > pq;
    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist > dis[u]) continue;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dist + w) {
                dis[v] = dist + w;
                pq.push({dis[v], v});
            }
        }
    }

    cout << (dis[t] == 1e18 ? -1 : dis[t]) << '\n';
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