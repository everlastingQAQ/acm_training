#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

class DSU {
    public: 
        vector <int> fa, rk, sz;
        int comps;
        DSU (int n = 0) {
            init(n); 
        }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            sz.assign(n + 1, 1);
            ranges::iota(fa, 0LL);
            comps = n;
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
            comps--;
            return true;
        }

        int size (int x) {
            return sz[find(x)];
        }
};

void solve ()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU df(n), gf(n);
    vector <array <int, 2> > f(m1 + 1), g(m2 + 1);
    vector <vector <int> > ef(n + 1);
    for (int i = 1; i <= m1; i++) {
        cin >> f[i][0] >> f[i][1];
        df.merge(f[i][0], f[i][1]);
    }

    for (int i = 1; i <= m2; i++) {
        cin >> g[i][0] >> g[i][1];
        gf.merge(g[i][0], g[i][1]);
    }

    int ans = 0;
    DSU nw(n);
    for (int i = 1; i <= m1; i++) {
        int u = f[i][0], v = f[i][1];
        if (gf.find(u) != gf.find(v)) {
            ans++;
        }else {
            nw.merge(u, v);
        }
    }

    ans += nw.comps - gf.comps;
    cout << ans << '\n';
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
