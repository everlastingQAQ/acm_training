#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, m; cin >> n >> m;
    vector <vector <array<int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    vector <int> dist(n + 1, -1e11);
    vector <int> inq(n + 1, 0);
    queue <int> q;

    q.push(1), dist[1] = 0, inq[1] = 1;

    while (q.size()) {
        int u = q.front();
        q.pop(), inq[u] = false;

        for (auto [v, w] : e[u]) {
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }

    cout << (dist[n] == -1e11 ? -1 : dist[n]) << '\n';
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