#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> fa, rk, sz;
    int comps;

    DSU(int n = 0) {
        init(n);
    }

    void init(int n) {
        fa.resize(n + 1);
        rk.assign(n + 1, 1);
        sz.assign(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
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

void solve ()
{
    int n, m;
    cin >> n >> m;
    
    vector <DSU> dsu(m + 1, DSU(n));

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dsu[w].merge(u, v);
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            if (dsu[i].find(u) == dsu[i].find(v)) ans++;
        }
        cout << ans << '\n';
    }
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