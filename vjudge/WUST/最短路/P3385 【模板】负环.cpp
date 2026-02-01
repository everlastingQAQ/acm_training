#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, m; cin >> n >> m;
    vector <vector <array<int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        if (w < 0) e[u].push_back({v, w});
        else e[u].push_back({v, w}), e[v].push_back({u, w});
    }

    vector <int> dist(n + 1, 1e14);
    vector <int> inq(n + 1, 0);
    vector <int> cnt(n + 1, 0);

    queue <int> q;
    q.push(1), dist[1] = 0, inq[1] = 1;

    while (q.size()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (auto [v, w] : e[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = 1;
                    if (++cnt[v] >= n) {
                        cout << "YES" << '\n';
                        return;
                    }
                }
            }
        }
    }

    cout << "NO" << '\n';
}   
    
signed main ()
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