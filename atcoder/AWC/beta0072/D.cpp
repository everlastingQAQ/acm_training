#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }

    int ans = 1;
    vector <int> vis(n + 1);
    vis[1] = true;
    auto dfs = [&] (auto self, int u, int cur) -> void {
        ans = max(ans, cur);
        sort(e[u].begin(), e[u].end(), [&] (auto a, auto b) {
            return val[a] < val[b];
        });
        for (auto v : e[u]) {
            if (vis[v]) continue;
            if (val[v] <= val[u]) continue;
            vis[v] = true;
            self(self, v, cur + 1);
        }
    };
    dfs(dfs, 1, 1);

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