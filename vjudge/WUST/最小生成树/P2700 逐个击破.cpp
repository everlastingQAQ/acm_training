#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU {
    public: 
        vector <int> fa, rk;
        vector <int> vis;
        DSU (int n = 0) {
            init(n); 
        }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            vis.assign(n + 1, 0);
            ranges::iota(fa, 0LL);
        }

        int find (int x) {
            return x == fa[x] ? x : (fa[x] = find(fa[x]));
        }

        bool merge (int i, int j) {
            int x = find(i), y = find(j);
            if (x == y) return false;
            if (rk[x] < rk[y]) swap(x, y);
            fa[y] = x;
            if (rk[x] == rk[y]) rk[x]++;
            vis[x] = vis[x] | vis[y];
            return true;
        }
};

void solve ()
{
    int n, k; cin >> n >> k;
    vector <int> vis(n + 1);
    DSU dsu(n);
    for (int i = 1; i <= k; i++) {
        int t; cin >> t;
        vis[++t] = true;
        dsu.vis[t] = 1;
    }
    
    vector <array<int, 3> > e;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        u++, v++;
        e.push_back({w, u, v});
    }
    ranges::sort(e, greater<>());
   
    int ans = 0;

    for (auto [w, u, v] : e) {
        u = dsu.find(u), v = dsu.find(v);
        if (u == v) continue;
        if (dsu.vis[u] && dsu.vis[v]) {
            ans += w;
        }else {
            dsu.merge(u, v);
        }
    }

    cout << ans << '\n';
    
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