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

        bool merge (int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return false;
            if (rk[x] < rk[y]) swap(x, y);
            fa[y] = x;
            if (rk[x] == rk[y]) rk[x]++;
            return true;
        }
};

int n, m;

void solve ()
{   
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        dsu.merge(a, b);
    }
    unordered_map <int, int> mp;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (!mp[dsu.find(i)]) {
            ans++;
            mp[dsu.find(i)]++;
        }
    }
    cout << ans << '\n';
}       
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int _ = 1;
    // cin >> _;
    // while (_--) {
    //     solve();
    // }
    while (cin >> n >> m) {
        if (n == 0) break;
        solve();
    }
    return 0;
} 