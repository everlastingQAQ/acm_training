#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <array <int, 2> > > e(n + 1);
    for (int i = 1; i <= n - m; i++) {
        int c;
        cin >> c;
        for (int j = 1; j <= c; j++) {
            int v, w;
            cin >> v >> w;
            e[i].push_back({v, w});
        }
    }
    vector <int> val(n + 1);
    vector <int> sz(n + 1, 0);
    for (int i = n - m + 1; i <= n; i++) {
        cin >> val[i];
        sz[i] = 1;
    }

    vector <vector <int> > dp(n + 1, vector <int> (m + 1, -1e11));

    auto dfs = [&] (auto self, int fa, int u) -> void {
        if (sz[u] == 1) dp[u][1] = val[u];
        dp[u][0] = 0;

        for (auto [v, w] : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
            for (int i = sz[u]; i >= 0; i--) {
                for (int j = 1; j <= sz[v]; j++) {
                    dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j] - w);
                }
            }
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0, 1);

    for (int i = m; i >= 1; i--) {
        if (dp[1][i] >= 0) {
            cout << i << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}   

int32_t main ()
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