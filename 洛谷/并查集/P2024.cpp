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
    int n, k; cin >> n >> k;

    DSU dsu (3 * n);

    int ans = 0;
    for (int i = 0; i < k; i++) {
        int z, x, y; cin >> z >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }

        if (z == 1) {
            if (dsu.find(x) == dsu.find(y + n) || dsu.find(x) == dsu.find(y + 2 * n)) {
                ans++;
                continue;
            }
            dsu.merge(x, y);
            dsu.merge(x + n, y + n);
            dsu.merge(x + 2 * n, y + 2 * n);
        }else {
            if (dsu.find(x) == dsu.find(y) || dsu.find(x) == dsu.find(y + 2 * n) || x == y) {
                ans++;  
                continue;
            }
            dsu.merge(x, y + n);
            dsu.merge(x + n, y + 2 * n);
            dsu.merge(x + 2 * n, y);
        }
    }   

    cout << ans << '\n';
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