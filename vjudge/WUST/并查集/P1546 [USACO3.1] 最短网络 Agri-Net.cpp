#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU {
    public:
        vector <int> fa, rk;
        DSU (int n = 0) { init(n); }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            iota(fa.begin(), fa.end(), 0LL);
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
    int n; cin >> n;
    vector <array<int, 3> > e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;
            if (i != j) e.push_back({w, i, j});
        }
    }  
    sort(e.begin(), e.end());

    DSU dsu(n);

    int ans = 0, cnt = 0;

    for (auto [w, u, v] : e) {
        u = dsu.find(u), v = dsu.find(v);
        if (u == v) continue;
        dsu.merge(u, v);
        ans += w;
        if (++cnt == n - 1) break;
    }

    cout << ans << '\n';
}   
    
int32_t main ()
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