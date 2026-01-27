#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int k, n, m; cin >> k >> n >> m;
    vector <int> pos(n + 1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> pos[i];
    }

    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }

    vector <int> vis(n + 1, 0), cnt(n + 1, 0);

    for (int i = 1; i <= k; i++) {
        ranges::fill(vis, 0);
        vis[pos[i]] = true;
        auto dfs = [&] (int u, auto self) -> void {
            cnt[u]++;
            for (auto x : e[u]) {
                if (vis[x]) continue;
                vis[x] = true;
                self(x, self);  
            }
        };
        dfs(pos[i], dfs);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (cnt[i] == k ? 1 : 0);

    cout << ans << '\n';
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