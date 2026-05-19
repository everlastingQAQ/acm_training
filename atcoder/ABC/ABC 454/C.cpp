#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    queue <int> q;
    vector <int> vis(n + 1);
    q.push(1);
    vis[1] = true;
    int ans = 1;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : e[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
                ans++;
            }
        }
    }
    cout << ans << '\n';
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