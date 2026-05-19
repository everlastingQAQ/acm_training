#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <array <int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    vector <int> dis1(n + 1, 1e18);
    vector <int> dis2(n + 1, 1e18);
    priority_queue <array <int, 2>, vector <array <int, 2> >, greater <array <int, 2> > > pq;
    dis1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist > dis2[u]) continue;
        for (auto [v, w] : e[u]) {
            if (dis1[v] > dist + w) {
                dis2[v] = dis1[v];
                dis1[v] = dist + w;
                pq.push({dis1[v], v});
            }else if (dis1[v] < dist + w && dist + w < dis2[v]) {
                dis2[v] = dist + w;
                pq.push({dis2[v], v});
            }
        }
    }

    cout << dis2[n] << '\n';
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