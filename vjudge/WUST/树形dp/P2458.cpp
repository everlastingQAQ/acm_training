#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > e(n + 1);
    vector <int> val(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i <= n; i++) {
        int u, c;
        cin >> u >> val[u] >> c;
        for (int j = 1; j <= c; j++) {
            int v;
            cin >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            ind[u]++;
            ind[v]++;
        }
    }

    vector <int> fa(n + 1);
    auto dfs1 = [&] (auto self, int fr, int u) -> void {
        fa[u] = fr;
        for (auto v : e[u]) {
            if (v == fr) continue;
            self(self, u, v);
        }
    };
    dfs1(dfs1, 0, 1);

    vector <array <int, 3> > dp(n + 1, {(int)1e8, (int)1e8, (int)1e8});
    auto dfs2 = [&] (auto self, int fr, int u) -> void {
        dp[u][0] = val[u];
        dp[u][2] = 0;
        int cur = 1e8;
        int t = 0;
        int mn = 1e8;
        for (auto v : e[u]) {
            if (v == fr) continue;
            self(self, u, v);
            dp[u][0] += min({dp[v][0], dp[v][1], dp[v][2]});
            if (fa[u] != 0) dp[u][2] += min(dp[v][1], dp[v][0]);
            t += min(dp[v][0], dp[v][1]);
            mn = min(mn, dp[v][0] - min(dp[v][0], dp[v][1]));
        }
        dp[u][1] = t + mn;
    };
    dfs2(dfs2, 0, 1);

    cout << min(dp[1][0], dp[1][1]) << '\n';

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