#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector <vector <array <i64, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    priority_queue <array <i64, 2>, vector <array <i64, 2> >, greater<> > pq;
    vector <i64> dis(n + 1, 1e14);

    pq.push({0, 1});
    dis[1] = 0;

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

    cout << (dis[t] == 1e14 ? -1 : 2 * dis[t]);
}   
    
int main ()
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