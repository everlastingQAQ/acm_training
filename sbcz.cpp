#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    vector<int> fa;

    DSU(int n = 0) { init(n); }

    void init(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        fa[y] = x;
        return true;
    }
};

struct DSU {
    vector <int> fa;
    DSU (int n = 0) {
        init(n);
    }

    void init (int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find (int x) {
        return (fa[x] == x ? x : fa[x] = find(fa[x]));
    }

    void merge (int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        fa[x] = y;
    }
};

void solve ()
{
    int n, m, s; cin >> n >> m >> s;
    vector <vector <array<i64, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }

    vector <i64 > dis(n + 1, 1e18);
    priority_queue <array <i64, 2>, vector <array <i64, 2> >, greater<array <i64, 2> > > pq;

    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist != dis[u]) continue;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dist + w) {
                dis[v] = dist + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main ()
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