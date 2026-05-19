#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector <vector <int> > dist(n + 5, vector <int> (n + 5, 2e18));
    vector <vector <int> > pass(n + 5, vector <int> (n + 5, 2e18));
    for (int i = 1; i <= m; i++) {
        int u, v, p, h;
        cin >> u >> v >> p >> h;
        dist[u][v] = min(dist[u][v], h);
        pass[u][v] = p;
    }

}   

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   