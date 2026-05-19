#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> val(n + 1);
    int mx = -1;
    int mn = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> val[i]; 
        mx = max(mx, val[i]);
        mn = min(mn, val[i]);
    }
    int res = mx - mn;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        e[u].push_back(v);
        if (k == 2) e[v].push_back(u);
    }

    vector <vector <int> > dis(3, vector <int> (n + 1, 1e18));
    priority_queue <array <int, 3>, vector <array <int, 3> >, greater <array <int, 3> > > pq;
    dis[0][1] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [dist, u, k] = pq.top();
        pq.pop();
        if (dist != dis[k][u]) continue;
        for (auto v : e[u]) {
            if (k == 0) {
                if (dis[k + 1][v] < -val[v]) {
                    dis[k + 1][v] = -val[v];
                    pq.push({dis[k + 1][v], v, k + 1});
                }
                pq.push({0, })
            }
        }
    }
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