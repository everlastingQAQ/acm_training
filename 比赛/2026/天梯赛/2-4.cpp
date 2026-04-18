#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <array <int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++) {
        if (e[i].empty()) continue;
        sort(e[i].begin(), e[i].end(), [] (auto a, auto b) {
            if (a[1] != b[1]) return a[1] > b[1];
            else return a[0] < b[0];
        });
    }

    int q;
    cin >> q;
    while (q--) {
        vector <int> vis(n + 1, 0);
        int x;
        cin >> x;
        vis[x] = 1;
        vector <int> ans;
        bool ok = false;
        auto dfs = [&] (auto self, int u) -> void {
            ans.push_back(u);
            if (e[u].size() == 0) {
                ok = true;
                return;
            } 
            bool ok1 = false;
            for (auto [v, w] : e[u]) {
                if (vis[v]) continue;
                ok1 = true;
                vis[v] = true;
                self(self, v);
                if (ok) return;
            }
            if (ok) return;
            if (!ok1) {
                ok = true;
                return;
            }
        };
        dfs(dfs, x);
        for (auto y : ans) {
            if (y == x) cout << y;
            else cout << "->" << y;
        }
        cout << '\n';
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