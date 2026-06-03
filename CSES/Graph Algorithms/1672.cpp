#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector <vector <int> > dis(n + 1, vector <int> (n + 1, 1e18));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min({dis[u][v], dis[v][u], w});
    }
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (dis[u][v] == 1e18 ? -1 : dis[u][v]) << '\n';
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