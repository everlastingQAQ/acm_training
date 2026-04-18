#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;

    vector <vector <array <int, 2> > > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    vector <vector <int> > dp(n + 1, vector <int> (m + 2));
    vector <int> sz(n + 1, 1);

    auto dfs = [&] (auto self, int fa, int u) -> void {
        sz[u] = 1;
        for (auto [v, w] : e[u]) {
            if (v == fa) continue;
            self(self, u, v);

            for (int i = sz[u]; i >= 0; i--) {
                for (int j = 1; j <= sz[v]; j++) {
                    if (i + j > m) break;
                    dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j - 1] + w);
                }
            }
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0, 1);

    cout << dp[1][m] << '\n';
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