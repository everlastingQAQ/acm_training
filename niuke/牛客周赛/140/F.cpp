#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    vector<int> fa, rk, sz;
    int comps;

    DSU(int n = 0) {
        init(n);
    }

    void init(int n) {
        fa.resize(n + 1);
        rk.assign(n + 1, 1);
        sz.assign(n + 1, 1);
        ranges::iota(fa, 0);
        comps = n;
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    bool merge(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;
        if (rk[x] < rk[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        if (rk[x] == rk[y]) rk[x]++;
        comps--;
        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }
};

void solve ()
{
	int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = ' ' + s;
    vector <vector <int> > e(n + 1);
    vector <array <int, 2> > edge; 
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge.push_back({u, v});
        if (((s[u] == 'A' || s[u] == 'B') && (s[v] == 'A' || s[v] == 'B')) || ((s[u] == 'C' || s[u] == 'D') && (s[v] == 'C' || s[v] == 'D'))) {
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }

    vector <int> vis(n + 1), a(n + 1);
    vector <array <int, 2> > ans;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        cnt++;
        bool ok = false;
        char c;
        if (s[i] == 'A') c = 'B';
        else if (s[i] == 'B') c = 'A';
        else if (s[i] == 'C') c = 'D';
        else c = 'C'; 
        auto dfs = [&] (auto self, int u) -> void {
            vis[u] = true;
            a[u] = cnt;
            if (s[u] == c) ok = true;
            for (auto v : e[u]) {
                if (vis[v]) continue;
                ans.push_back({u, v});
                self(self, v);
            }
        };  
        dfs(dfs, i);
        if (!ok) {
            cout << "No\n";
            return;
        }
    }

    DSU dsu(cnt);
    
    for (auto [u, v] : edge) {
        int x = a[u], y = a[v];
        if (x == y) continue;
        if (dsu.merge(x, y)) {
            ans.push_back({u, v});
        }
    }

    if (ans.size() != n - 1) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
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