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
            if (sz[x] >= sz[y]) fa[x] = y;
            else fa[y] = fa[x];
            if (sz[x] == sz[y] && x != y) sz[y]++;
        }
};

void solve ()
{
    int n, m; cin >> n >> m;
    vector <array<int, 3> > v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    } 

    ranges::sort(v, [] (auto a1, auto b1) {
        return a1[2] > b1[2];
    });

    DSU dsu(2 * n);

    for (int i = 0; i < m; i++) {
        auto [x, y, z] = v[i];
        if (dsu.find(x) == dsu.find(y) || dsu.find(x + n) == dsu.find(y + n)) {
            cout << z << '\n';
            return;
        }else {
            dsu.merge(x, y + n);
            dsu.merge(x + n, y);
        }
    }

    cout << 0 << '\n';
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