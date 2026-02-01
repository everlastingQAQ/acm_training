#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, m; cin >> n >> m;
    vector <vector <array <int, 2> > > e(n + 1), E(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    int ans = 0;
    vector <int> dis(n + 1, 1e11);
    priority_queue <array<int, 2>, vector <array <int, 2> >, greater<array <int, 2> > > pq;

    pq.push({0, 1}), dis[1] = 0;

    while (pq.size()) {
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

    for (int i = 1; i <= n; i++) ans += dis[i];

    dis.assign(n + 1, 1e11);
    pq.push({0, 1}), dis[1] = 0;

    while (pq.size()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist != dis[u]) continue;
        for (auto [v, w] : E[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    } 

    for (int i = 1; i <= n; i++) ans += dis[i];

    cout << ans << '\n';

}   
    
signed main ()
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