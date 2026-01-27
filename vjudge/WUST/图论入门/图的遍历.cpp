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
        e[v].push_back(u);
    }

    vector <int> ans(n + 1, 0);

    auto dfs = [&] (int fa, int u, auto self) -> void {
        if (ans[u] == 0) ans[u] = fa;
        else return;

        for (auto v : e[u]) {
            self(fa, v, self);
        }
    };

    for (int i = n; i >= 1; i--) {
        dfs(i, i, dfs);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
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