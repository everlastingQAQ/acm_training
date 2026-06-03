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
        e[v].push_back(u);
    }
    vector <int> ans(n + 1, -1);
    vector <int> vis(n + 1);
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        auto dfs = [&] (auto self, int u, int cur) -> void {
            if (ans[u] != -1) ok = false;
            if (!ok) return;
            ans[u] = cur;
            for (auto v : e[u]) {
                if (vis[v]) {
                    if ((ans[v] ^ 1) != ans[u]) {
                        ok = false;
                        return;
                    }
                    continue;
                }
                vis[v] = true;
                self(self, v, cur ^ 1);
                if (!ok) return;
            }
        };
        dfs(dfs, i, 0);
        if (!ok) break;
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        cout << (ans[i] == 0 ? 2 : 1) << ' ';
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