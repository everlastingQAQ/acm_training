#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector <int> fa(n + 1);
    vector <int> dep(n + 1);
    fa[1] = 0;
    dep[0] = -1;

    auto dfs = [&] (auto self, int f, int u) -> void {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        for (auto v : e[u]) {
            if (v == f) continue;
            self(self, u, v);
        }
    };
    dfs(dfs, 0, 1);

    int m = __lg(n);
    vector <vector <int> > st(n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i++) {
        st[i][0] = fa[i];
    }
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= n; i++) {
            st[i][k] = st[st[i][k - 1]][k - 1];
        }
    } 

    auto lca = [&] (int u, int v) -> int {
        if (dep[u] < dep[v]) swap(u, v);
        if (dep[u] > dep[v]) {
            for (int k = m; k >= 0; k--) {
                if (dep[st[u][k]] >= dep[v]) {
                    u = st[u][k];
                }
            }
        }
        if (u == v) return u;
        for (int k = m; k >= 0; k--) {
            if (st[u][k] != st[v][k]) {
                u = st[u][k];
                v = st[v][k];
            }
        }

        return fa[u];
    };

    auto dis = [&] (int a, int b) -> int {
        int c = lca(a, b);
        return dep[c] - dep[a] + dep[c] - dep[b];
    };

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = lca(a, b);
        int y = lca(c, d);
        if (dis(x, c) + dis(x, d) == dis(c, d) || dis(y, a) + dis(y, b) == dis(a, b)) {
            cout << "Y\n";
        }else {
            cout << "N\n";
        }
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