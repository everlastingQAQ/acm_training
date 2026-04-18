#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }

    vector <int> sz(n + 1);
    vector <int> fa(n + 1);
    fa[1] = 0;
    auto dfs = [&] (auto self, int f, int u) -> void {
        fa[u] = f;
        sz[u] = 1;
        for (auto v : e[u]) {
            if (v == f) continue;
            self(self, u, v);
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0, 1);

    vector <int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        vector <int> a;
        for (auto v : e[i]) {
            if (v == fa[i]) a.push_back(n - sz[i]);
            else a.push_back(sz[v]);
        }
        vector <int> dp(n, 0);
        dp[0] = 1;
        for (auto x : a) {
            for (int j = n - 1; j >= x; j--) {
                dp[j] |= dp[j - x];
            }
        }
        for (int x = 1; x <= n - 2; x++) {
            if (dp[x]) vis[x] = true;
        }
    }

    vector <array <int, 2> > ans;
    ans.reserve(3 * n + 1);

    for (int x = 1; x <= n - 2; x++) {
        if (vis[x]) {
            ans.push_back({x, n - 1 - x});
        }
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

int main ()
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