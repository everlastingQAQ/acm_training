#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector <int> dep(n + 1);
    dep[k] = 1;
    int ans = 0;
    auto dfs = [&] (auto self, int fa, int u) -> void {
        for (auto v : e[u]) {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            ans = max(ans, dep[v]);
            self(self, u, v);
        }
    };
    dfs(dfs, 0, k);
    cout << ans << '\n';
}   
    
int32_t main ()
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