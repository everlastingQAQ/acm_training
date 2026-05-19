#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <array <int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    vector <vector <int> > dis(k + 1, vector <int> (n + 1, 1e18));
    dis[0][1] = 0;
    priority_queue <array <int, 3>, vector <array <int, 3> >, greater<array <int, 3> > > pq;
    pq.push({0, 1, 0});
    
    while (!pq.empty()) {
        auto [dist, u, cnt] = pq.top();
        pq.pop();
        if (dist != dis[cnt][u]) continue;
        for (auto [v, w] : e[u]) {
            if (dis[cnt][v] > max(dist, w)) {
                dis[cnt][v] = max(dist, w);
                pq.push({dis[cnt][v], v, cnt});
            }
            if (cnt < k && dis[cnt + 1][v] > dist) {
                dis[cnt + 1][v] = dist;
                pq.push({dis[cnt + 1][v], v, cnt + 1});
            }
        }
    }

    int ans = 1e18;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dis[i][n]);
    }
    cout << (ans == 1e18 ? -1 : ans) << '\n';
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