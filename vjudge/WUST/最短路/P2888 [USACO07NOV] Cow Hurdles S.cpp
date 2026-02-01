#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, q; cin >> n >> m >> q;
    vector <vector <int> > dist(n + 5, vector <int> (n + 5, 1e14));
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || i == k || j == k) continue;
                if (dist[i][k] == 1e14 || dist[k][j] == 1e14) continue;
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
            }
        }
    }

    while (q--) {
        int u, v; cin >> u >> v;
        cout << (dist[u][v] == 1e14 ? -1 : dist[u][v]) << '\n';
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