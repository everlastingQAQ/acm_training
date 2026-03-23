#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

class DSU {
    public: 
        vector <int> fa, rk, sz;
        DSU (int n = 0) {
            init(n); 
        }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            sz.assign(n + 1, 1);
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
            sz[x] += sz[y]; 
            if (rk[x] == rk[y]) rk[x]++;
            return true;
        }

        bool judge (int i, int j) {
            int x = find(i), y = find(j);
            return x == y;
        }

        int size (int x) {
            return sz[find(x)];
        }
};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int q;
    cin >> q;
    vector <int> a(q + 1);
    vector <int> vis(n + 1, true);
    
    for (int i = 1; i <= q; i++) {
        cin >> a[i];
        a[i]++;
        vis[a[i]] = false;
    }

    DSU dsu(n);
    vector <int> b(n + 1, 0);
    int cnt = n;

    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            for (auto u : e[i]) {
                if (!vis[u]) continue;
                if (!dsu.judge(i, u)) {
                    cnt--;
                    dsu.merge(i, u);
                }
            }
        }
    }

    vector <int> ans;
    ans.push_back(cnt - q);
    for (int i = q; i >= 1; i--) {
        int u = a[i];
        vis[u] = true;
        for (auto v : e[u]) {
            if (!vis[v]) continue;
            if (!dsu.judge(u, v)) {
                cnt--;
                dsu.merge(u, v);
            }
        }
        ans.push_back(cnt - i + 1);
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << '\n';
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