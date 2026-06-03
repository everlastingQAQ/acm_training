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

    vector <int> a(n + 1);
    vector <int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        auto dfs = [&] (auto self, int pre, int u) -> void {
            for (auto v : e[u]) {
                if (v == pre) continue;
                if (!vis[v]) {
                    a[v] = u;
                    vis[v] = true;
                    self(self, u, v);
                }else {
                    vector <int> ans;
                    ans.push_back(v);
                    int cur = u;
                    while (cur != v) {
                        ans.push_back(cur);
                        cur = a[cur];
                    }
                    cout << ans.size() + 1 << '\n';
                    cout << ans.back() << ' ';
                    for (auto x : ans) {
                        cout << x << ' ';
                    }
                    exit(0);
                }
            }
        };
        dfs(dfs, -1, i);
    }
    cout << "IMPOSSIBLE\n";
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