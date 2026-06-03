#include <bits/stdc++.h>
using namespace std;
#define int long long

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
        iota(fa.begin(), fa.end(), 0);
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
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue <int> q;
    q.push(1);
    vector <int> vis(n + 1);
    vis[1] = true;
    vector <int> a(n + 1);
    a[1] = -1;
    bool ok = false;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        if (u == n) {
            ok = true;
            break;
        }
        for (auto v : e[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            a[v] = u;
            q.push(v);
        }
    }
    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    int cur = n;
    vector <int> ans;
    while (cur != -1) {
        ans.push_back(cur);
        cur = a[cur];
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << ' ';
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