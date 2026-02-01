#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m; cin >> n >> m;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector <vector <int> > dist(n + 1, vector <int> (n + 1, 1e14));
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u++, v++;
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }
    int q; cin >> q;
    
    int k = 1;
    while (q--) {
        int x, y, t; cin >> x >> y >> t;
        x++, y++;
        while (k <= n && a[k] <= t) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
            k++;
        } 
        if (a[x] > t || a[y] > t || dist[x][y] == 1e14) {
            cout << -1 << '\n';
        }else {
            cout << dist[x][y] << '\n';
        }
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