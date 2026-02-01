#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, m; cin >> n >> m;
    vector <vector <array <int, 2> > > e(n + 1);
    vector <array<int, 3> > E(m + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        E[i][0] = u, E[i][1] = v, E[i][2] = w;
        e[u].push_back({v, 0});
        e[v].push_back({u, 0});
    }
    int d; cin >> d;
    
    for (int i = 1; i <= d; i++) {
        int x, y; cin >> x >> y;
        int t = 0;
        for (auto [u, v, w] : E) {
            if (u == x && v == y || u == y && v == x) {
                t = w;
                break;
            }
        }
        for (auto &[k, w] : e[x]) {
            if (y == k) {
                w = t;
                break;
            }
        }
        for (auto &[k, w] : e[y]) {
            if (x == k) {
                w = t;
                break;
            }
        }
    }

    int s, t; cin >> s >> t;
    vector <int> dis(n + 1, 1e14);
    priority_queue <array<int, 2>, vector <array<int, 2> >, greater<array<int, 2> > > pq;

    pq.push({0, s}), dis[s] = 0;

    while (pq.size()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist != dis[u]) continue;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    cout << dis[t] << '\n';
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