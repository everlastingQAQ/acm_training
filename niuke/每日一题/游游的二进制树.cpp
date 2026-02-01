#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s; s = ' ' + s;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int ans = 0;

    auto dfs = [&] (int fa, int u, int t, auto self) -> void {
        if (t > r) return;
        if (t >= l && t <= r && fa != 0) ans++;

        for (auto v : e[u]) {
            if (v == fa) continue;
            self(u, v, (t << 1) + s[v] - '0', self);
        }
        
    };

    for (int i = 1; i <= n; i++) {
        dfs(0, i, s[i] - '0', dfs);
    }

    cout << ans << '\n';
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