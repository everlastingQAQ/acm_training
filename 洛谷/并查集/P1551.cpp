#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

class DSU {
    public:
        vector <int> fa, sz;
        DSU (int n) {
            if (n) init(n);
        }

        void init (int n) {
            fa.resize(n + 1);
            sz.assign(n + 1, 1);
            for (int i = 1; i <= n; i++) fa[i] = i;
        }

        int find (int x) {
            return x == fa[x] ? x : (fa[x] = find(fa[x]));
        }

        void merge (int i, int j) {
            int x = find(i), y = find(j);
            if (sz[x] <= sz[y]) fa[x] = y;
            else fa[y] = x;
            if (sz[x] == sz[y] && x != y) sz[y]++;
        }
};

void solve ()
{
    int n, m, p; cin >> n >> m >> p;
    vector <int> fa(n + 1), rk(n + 1, 1);
    for (int i = 1; i <= n; i++) fa[i] = i;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        dsu.merge(x, y);
    }

    for (int i = 0; i < p; i++) {
        int x, y; cin >> x >> y;
        cout << (dsu.find(x) == dsu.find(y) ? "Yes" : "No") << '\n';
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