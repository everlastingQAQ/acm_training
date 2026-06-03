#include <bits/stdc++.h>
using namespace std;
#define int long long

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
    using arr3 = array <int, 3>;
    using arr2 = array <int, 2>;
    vector <arr3> e;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }

    for (int i1 = 0; i1 < 3; i1++) {
        for (int i2 = i1 + 1; i2 < 3; i2++) {
            DSU dsu(n);
            vector <arr2> ans;

            bool ok = false;
            for (auto [u, v, w] : e) {
                if (w == i1) {
                    ans.push_back({u, v});
                    dsu.merge(u, v);
                    ok = true;
                    break;
                }
            }
            if (!ok) continue;
            ok = false;
            for (auto [u, v, w] : e) {
                if (w == i2) {
                    ans.push_back({u, v});
                    dsu.merge(u, v);
                    ok = true;
                    break;
                }
            }
            if (!ok) continue;

            for (auto [u, v, w] : e) {
                if (w != i1 && w != i2) continue;
                if (dsu.merge(u, v)) {
                    ans.push_back({u, v});
                }
            }
            if (dsu.comps == 1) {
                for (auto [u, v] : ans) {
                    cout << u << ' ' << v << '\n';
                }
                return;
            }
        }
    }
    cout << -1;
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