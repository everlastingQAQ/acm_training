#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;

i64 qpow (i64 a, i64 b) {
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

        int size (int x) {
            return sz[find(x)];
        }
};

void solve ()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector <array <int, 2> > e(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> e[i][0] >> e[i][1];
    }

    i64 ans = 0;
    int cnt = n;
    for (int i = m; i >= 1; i--) {
        if (dsu.find(e[i][0]) != dsu.find(e[i][1])) {
            if (cnt > 2) {
                dsu.merge(e[i][0], e[i][1]);
                cnt--;
            }else {
                ans = (ans + qpow(2, i)) % mod;
            }   
        }
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