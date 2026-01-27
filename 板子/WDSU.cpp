#include <bits/stdc++.h>
using namespace std;
#define int long long

class WDSU {
    public: 
        vector <int> fa, rk;
        vector <int> dist;
        WDSU (int n = 0) { init(n); }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            dist.assign(n + 1, 0);
            iota(fa.begin(), fa.end(), 0LL);
        }

        int find (int x) {
            if (fa[x] == x) return x;
            int t = fa[x];
            fa[x] = find(fa[x]);
            dist[x] += dist[t];
            return fa[x];
        }

        bool merge (int x, int y, int diff) {
            int rx = find(x), ry = find(y);
            if (rx == ry) return (dist[y] - dist[x] == diff);

            if (rk[rx] < rk[ry]) {
                fa[rx] = ry;
                dist[rx] = dist[y] - dist[x] - diff;
            }else {
                fa[ry] = rx;
                dist[ry] = dist[x] - dist[y] + diff;
                if (rk[rx] == rk[ry]) rk[rx]++;
            }
            return true;
        }

        bool same (int x, int y) { return (find(x) == find(y) ? 1 : 0); }

        int query (int x, int y) {
            return dist[y] - dist[x];
        };  
};

void solve ()
{
    int n, m;
    while (cin >> n >> m) {
        WDSU dsu(n);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int a, b, s; cin >> a >> b >> s;
            if (!dsu.merge(a - 1, b, s)) ans++;
        }
        cout << ans << '\n';
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
