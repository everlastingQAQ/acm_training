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
    vector <vector <int> > e(n + 1);
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    DSU dsu(n + 2); 
    vector <int> vis(n + 1);
    
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        queue <array <int, 2> > q;
        q.push({i, 1});
        while (!q.empty()) {
            auto [u, cnt] = q.front();
            q.pop();
            vis[u] = true;
        }
    }
    
    // cout << 9;
    map <int, int> mp;
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        int r = dsu.find(i);
        if (!mp[r]) {
            ans.push_back(dsu.size(i));
            mp[r] = 1;
        }
    }

    if (ans.size() == 1) {
        cout << 1 << '\n';
        cout << ans.back() - 2 << '\n';
    }else {
        cout << 2 << '\n';
        sort(ans.begin(), ans.end());
        cout << ans[0] - 1 << ' ' << ans[1] - 1<< '\n';
    }
}

int main ()
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