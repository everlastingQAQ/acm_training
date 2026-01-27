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
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int m; cin >> m;
        DSU dsu(n);
        for (int i = 1; i <= m; i++) {
            int a, b; cin >> a >> b;
            dsu.merge(a, b);
        }
        map <int, int> mp;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int t = dsu.find(i);
            if (mp[t] == 0) ans++;
            mp[t] = 1;
        }
        cout << ans - 1 << '\n';
    }
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