#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

class DSU {
    public: 
        vector <int> fa, rk, sz;
        int comps; //联通块数
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
    int n;
    cin >> n;
    vector <array <int, 3> > e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val;
            cin >> val;
            if (i == j) {
                e.push_back({val, 0, i});
            }else if (i > j) {
                e.push_back({val, i, j});
            }
        }
    }

    sort(e.begin(), e.end());
    DSU dsu(n + 1);
    int ans = 0;

    for (auto [w, u, v] : e) {
        u = dsu.find(u), v = dsu.find(v);
        if (!dsu.merge(u, v)) continue;
        ans += w;
        if (dsu.comps == 1) break;
    }

    cout << ans << '\n';
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