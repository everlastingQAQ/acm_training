#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <array <int, 2> > > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i <= n; i++) {
        int u = i;
        int v, w;
        cin >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
        ind[u]++;
        ind[v]++;
    }
    
    vector <int> val(n + 1);
    vector <array <int, 2> > p;
    int ans = 0;
    for (auto [x, w] : e[0]) {
        int res = w;
        val[x] = w;
        auto dfs = [&] (auto self, int fa, int u) -> void {
            int cur = 1e8;
            for (auto [v, w] : e[u]) {
                if (v == fa) continue;
                val[v] = w;
                cur = min(cur, val[v]);
                self(self, u, v);
            }
            res = min(res, cur);
        };  
        dfs(dfs, 0, x);
        ans = max(ans, res);
    }
    vector <int> tt;
    
    vector <int> fa(n + 1);
    auto dfs1 = [&] (auto self, int f, int u) -> void {
        fa[u] = f;
        for (auto [v, w] : e[u]) {
            if (v == f) continue;
            self(self, u, v);
        }
    };
    dfs1(dfs1, -1, 0);

    for (int i = 1; i < n; i++) {
        // cout << i << ' ' << ind[i] << '\n';
        if (ind[i] == 1) {
            int x = i;
            int cur = val[x];
            // if (i == 8) cout << cur << '\n';
            while (x != 0) {
                // if (i == 8) cout << val[x] << '\n';
                cur = min(cur, val[x]);
                x = fa[x];
                if (x == fa[x]) break;
            }
            // if (i == 8) cout << cur << '\n';
            if (cur == ans) {
                tt.push_back(i);
            }
        }
    }

    cout << ans << '\n';
    for (auto x : tt) {
        cout << x << " \n"[x == tt.back()];
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}