#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, m, l, s, t; cin >> n >> m >> l >> s >> t;
    vector <vector <array<int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }

    set <int> ans;
    
    auto dfs = [&] (int u, int sum, int step, auto self) -> void {
        if (step == l) {
            if (sum >= s && sum <= t) ans.insert(u);
            return;
        }
        for (auto [x, w] : e[u]) {
            self(x, sum + w, step + 1, self);
        }
    };

    dfs(1, 0, 0, dfs);

    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}   
    
signed main ()
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