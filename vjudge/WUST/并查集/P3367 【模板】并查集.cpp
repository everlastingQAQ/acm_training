#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

class DSU {
    public: 
        vector <int> fa, rk;
        DSU (int n = 0) {
            init(n); 
        }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
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
            return true;
        }
};

void solve ()
{
    int n, m; cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int op; cin >> op;
        if (op == 1) {
            int a, b; cin >> a >> b;
            dsu.merge(a, b);
        }else if (op == 2) {
            int a, b; cin >> a >> b;
            if (dsu.find(a) == dsu.find(b)) {
                cout << 'Y' << '\n';
            }else {
                cout << 'N' << '\n';
            }
        }
    }
}   
    
signed main ()
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
