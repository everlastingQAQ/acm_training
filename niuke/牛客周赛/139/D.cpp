#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;

i64 qpow (i64 a, i64 b)
{
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

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
    int n, k;
    cin >> n >> k;
    DSU dsu(n);
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }
    cout << qpow(26, dsu.comps) << '\n';
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
