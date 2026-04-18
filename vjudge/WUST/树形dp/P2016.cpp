#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > e(n);
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        int c;
        cin >> c;
        for (int j = 1; j <= c; j++) {
            int v;
            cin >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }

    vector <array <int, 2> > dp(n + 1, {1000000, 10000000});
    
    auto dfs = [&] (auto self, int fa, int u) -> void {
        int a1 = 0, a2 = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
            a1 += dp[v][1];
            a2 += min(dp[v][1], dp[v][0]);
        }
        dp[u][0] = a1;
        dp[u][1] = a2;
    };
    dfs(dfs, -1, 0);

    cout << min(dp[0][0], dp[0][1]) << '\n';
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