#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, m; cin >> n >> m;
    vector <vector <int> > dis(n + 1, vector <int> (n + 1, 1e16));
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    for (int i = 1; i <= n; i++) dis[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int ans = 1e16; 
    for (int p = 1; p <= n; p++) {
        for (int q = p + 1; q <= n; q++) {
            vector <vector <int> > dist(n + 1, vector <int> (n + 1, 1e16));
            dist = dis;
            dist[p][q] = 0, dist[q][p] = 0;
            int cur = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][p] + dist[p][j]);
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][q] + dist[q][j]);
                    cur += dist[i][j];
                }
            }
            ans = min(cur / 2, ans);
        }
    }

    cout << ans << '\n';
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