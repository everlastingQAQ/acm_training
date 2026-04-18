#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector <array <i64, 2> > dp(n + 1, {1, 1});

    auto dfs = [&] (auto self, int fa, int u) -> void {
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
            dp[u][0] = dp[v][1] * dp[u][0] % mod;
            dp[u][1] = (dp[u][1] * (dp[v][0] + dp[v][1]) % mod) % mod;
        }
    };
    dfs(dfs, 0, 1);

    cout << (dp[1][0] + dp[1][1]) % mod << '\n';
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