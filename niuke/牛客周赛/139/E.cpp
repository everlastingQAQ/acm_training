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

    vector <array <int, 2> > dp(n + 1);

    auto dfs = [&] (auto self, int fa, int u) -> void {
        int a1 = 0, a2 = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
            a1 += dp[v][1];
            a2 += min(dp[v][0], dp[v][1]);
        }
        dp[u][0] = a1;
        dp[u][1] = a2;
    };
    dfs(dfs, 0, 1);

    for (int i = 1; i <= n; i++) {
        cout << min(dp[i][0], dp[i][1]) << " \n"[i == n];
    }
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 
