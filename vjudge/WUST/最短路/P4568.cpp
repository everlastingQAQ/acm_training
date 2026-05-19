#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, k, st, en;
    cin >> n >> m >> k >> st >> en;
    st++, en++;
    vector <vector <array <int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    vector <vector <int> > dis(k + 1, vector <int> (n + 1, 2e18));
    dis[0][st] = 0;
    priority_queue <array <int, 3>, vector <array <int, 3> >, greater<array <int, 3> > > pq;
    pq.push({0, st, 0});
    while (!pq.empty()) {
        auto [dist, u, cnt] = pq.top();
        pq.pop();
        if (dist != dis[cnt][u]) continue;
        for (auto [v, w] : e[u]) {
            if (dis[cnt][v] > dist + w) {
                dis[cnt][v] = dist + w;
                pq.push({dis[cnt][v], v, cnt});
            }
            if (cnt < k && dis[cnt + 1][v] > dist) {
                dis[cnt + 1][v] = dist;
                pq.push({dis[cnt + 1][v], v, cnt + 1});
            }
        }
    } 
    int ans = 2e18;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dis[i][en]);
    }
    cout << ans << '\n';
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