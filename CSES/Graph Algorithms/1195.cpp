#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    using arr2 = array <int, 2>;
    using arr3 = array <int, 3>;
    vector <vector <arr2> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    vector <vector <int> > dis(2, vector <int> (n + 1, 1e18));
    dis[0][1] = 0;
    dis[1][1] = 0;
    priority_queue <arr3, vector <arr3>, greater <arr3> > pq;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [dist, u, k] = pq.top();
        pq.pop();
        if (dis[k][u] < dist) continue;
        for (auto [v, w] : e[u]) {
            if (dis[k][v] > dist + w) {
                dis[k][v] = dist + w;
                pq.push({dis[k][v], v, k});
            }
            if (k == 0) {
                if (dis[k + 1][v] > dist + w / 2) {
                    dis[k + 1][v] = dist + w / 2;
                    pq.push({dis[k + 1][v], v, k + 1});
                }
            }
        }
    }

    cout << dis[1][n] << '\n';
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