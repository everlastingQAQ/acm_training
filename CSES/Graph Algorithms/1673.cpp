#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <array <int, 2> > > e(n + 1), rev(n + 1);
    vector <int> dis(n + 1, -1e18);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        rev[v].push_back({u, w});
    }

    vector <int> can(n + 1);
    can[n] = 1;
    queue <int> qq;
    qq.push(n);

    while (!qq.empty()) {
        auto u = qq.front();
        qq.pop();
        for (auto [v, w] : rev[u]) {
            if (!can[v]) {
                can[v] = 1;
                qq.push(v);
            }
        }
    }

    dis[1] = 0;
    queue <int> q;
    vector <int> vis(n + 1);
    vector <int> cnt(n + 1);
    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto [v, w] : e[u]) {
            if (!can[v]) continue;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                    if (++cnt[v] >= n && can[v]) {
                        cout << -1 << '\n';
                        return;
                    }
                }
            } 
        }
    }

    cout << dis[n] << '\n';
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