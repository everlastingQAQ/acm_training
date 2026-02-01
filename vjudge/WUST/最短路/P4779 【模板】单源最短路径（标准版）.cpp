#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, m, s; cin >> n >> m >> s;
    vector <vector <array<int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }

    vector <int> dis(n + 1, 1e14);
    priority_queue <array<int, 2>, vector <array<int, 2> > , greater<array<int, 2> > > pq;

    pq.push({0, s}), dis[s] = 0;

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

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
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