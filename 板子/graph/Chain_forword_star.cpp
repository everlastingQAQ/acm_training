#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct graph {
    struct edge {
        int to, nxt;
    };

    int n;
    vector <edge> e;
    vector <int> head;

    graph (int n = 0, int m = 0) {
        init(n, m);
    }

    void init (int _n, int m) {
        n = _n;
        head.assign(n + 1, -1);
        e.reserve(m);
    }

    void add (int u, int v) {
        e.push_back({v, head[u]});
        head[u] = e.size() - 1;
    }
};

void solve ()
{
    int n, m;
    cin >> n >> m;
    graph g(n, m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g.add(u, v);
    }

    vector <int> vis(n + 1, 0);
    auto dfs = [&] (auto self, int fa, int u) -> void {
        vis[u] = 1;
        for (int i = g.head[u]; i != -1; i = g.e[i].nxt) {
            int v = g.e[i].to;
            if (vis[v]) continue;
            self(self, u, v);
        }
    };
    dfs(dfs, 0, 1);
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}