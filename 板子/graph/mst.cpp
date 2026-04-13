#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    vector<int> fa, rk, sz;
    int comps;//连通块数

    DSU(int n = 0) {
        init(n);
    }

    void init(int n) {
        fa.resize(n + 1);
        rk.assign(n + 1, 1);
        sz.assign(n + 1, 1);
        ranges::iota(fa, 0);
        comps = n;
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    bool merge(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;
        if (rk[x] < rk[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        if (rk[x] == rk[y]) rk[x]++;
        comps--;
        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<i64, 3>> e;
    for (int i = 0; i < m; i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        e.push_back({w, u, v});
    }

    sort(e.begin(), e.end());

    DSU dsu(n);
    i64 ans = 0;

    for (auto [w, u, v] : e) {
        if (dsu.merge(u, v)) {
            ans += w;
            if (dsu.comps == 1) break;
        }
    }

    if (dsu.comps != 1) {
        cout << "orz\n";
    } else {
        cout << ans << '\n';
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
