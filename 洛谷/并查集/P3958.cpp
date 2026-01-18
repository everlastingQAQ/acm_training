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
            fa.resize(n + 3);
            sz.assign(n + 3, 1);
            for (int i = 1; i <= n; i++) fa[i] = i;
            fa[n + 1] = n + 1;//top
            fa[n + 2] = n + 2;//down
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
    int n, h, r; cin >> n >> h >> r;
    vector <array<int, 3> > v(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    DSU dsu(n);

    auto dist = [&] (int x1, int y1, int z1, int x2, int y2, int z2) -> int {
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1);
    };

    for (int i = 1; i <= n; i++) {
        if (v[i][2] + r >= h) dsu.merge(i, n + 1);
        if (v[i][2] - r <= 0) dsu.merge(i, n + 2);
    }

    for (int i = 1; i <= n; i++) { 
        for (int j = i + 1; j <= n; j++) {
            if (dist(v[i][0], v[i][1], v[i][2], v[j][0], v[j][1], v[j][2]) <= 4 * r * r) {
                dsu.merge(i, j);
            }
        }
    }

    cout << (dsu.find(n + 1) == dsu.find(n + 2) ? "Yes" : "No") << '\n';    
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}