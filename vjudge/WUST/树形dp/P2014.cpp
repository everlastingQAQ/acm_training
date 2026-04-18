#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> val(n + 1);
    vector <int> r;
    for (int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        e[i].push_back(v);
        e[v].push_back(i);
        val[i] = w;
    }

    vector <vector <int> > dp(n + 1, vector <int> (m + 5));
    vector <int> sz(n + 1);

    auto dfs = [&] (auto self, int fa, int u) -> void {
        sz[u] = 1;
        dp[u][1] = val[u];
        for (auto v : e[u]) {
            if (v == fa) continue;

            self(self, u, v);

            for (int j = min(m + 1, sz[u] + sz[v]); j >= 1; j--) {
                for (int k = 1; k <= min(sz[v], j - 1); k++) {
                    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
                }
            }   

            sz[u] += sz[v];
        }
    };
    dfs(dfs, -1, 0);

    cout << dp[0][m + 1] << '\n';
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