#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <i64> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    vector <vector <i64> > e(n + 1);
    for (int i = 2; i <= n; i++) {
        int v;
        cin >> v;
        e[i].push_back(v);
        e[v].push_back(i);
    }

    vector <i64> ans(n + 1, 0);

    auto dfs = [&] (auto self, int u, int fa) -> void {
        ans[u] += ans[fa] + val[u];
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, v, u);
        }
    };

    dfs(dfs, 1, 0);

    while (q--) {
        int t;
        cin >> t;
        cout << ans[t] << '\n';
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