#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, m; cin >> n >> m;
    vector <vector <int> > e(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        ranges::sort(e[i]);
    }

    vector <int> vis(n + 1, 0);
    auto dfs = [&] (int u, auto self) -> void {
        cout << u << ' ';
        for (auto v : e[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            self(v, self);
        }
    };

    vis[1] = true;
    dfs(1, dfs);

    cout << '\n';
    vis.assign(n + 1, 0);

    queue <int> q;
    q.push(1);
    vis[1] = true;
    
    while (q.size()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (auto v : e[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            q.push(v);
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