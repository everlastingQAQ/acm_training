#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector <int> sz(n + 1, 0);
    int ans = 0;

    auto dfs = [&] (int fa, int u, auto self) -> void {
        sz[u] = 1;
        bool found = false;
        int sum = 0;
        for (int v : e[u]) {
            if (v == fa) continue;
            self(u, v, self);
            sz[u] += sz[v];
            sum += sz[v];
            if (!(sz[v] & 1)) found = true;
        }
        if (!((n - 1 - sum) & 1) && n - 1 - sum != 0) found = true;
        
        if (!found) ans++;
    };

    dfs(0, 1, dfs);

    cout << ans << '\n';
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