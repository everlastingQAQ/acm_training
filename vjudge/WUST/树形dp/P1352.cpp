#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    vector <int> f(n + 1);
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        f[u] = v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int r = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == 0) {
            r = i;
            break;
        }
    }

    vector <array <int, 2> > dp(n + 1);
    
    auto dfs = [&] (auto self, int fa, int u) -> void {
        int c1 = 0, c2 = max(0, val[u]);
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
            c1 += max(dp[v][0], dp[v][1]);
            c2 += dp[v][0];
        }   
        dp[u][0] = c1;
        dp[u][1] = c2;
    };
    dfs(dfs, 0, r);

    cout << max(dp[r][0], dp[r][1]) << '\n';
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