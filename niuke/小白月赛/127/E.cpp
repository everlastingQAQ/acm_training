#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int mod = 998244353;

void solve ()
{
    int n; cin >> n;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector <int> dep(n + 1); dep[1] = 0;
    vector <int> siz(n + 1);

    auto dfs = [&] (int fa, int u, auto self) -> void {
        siz[u] = 1;
        dep[u] = dep[fa] + 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(u, v, self);
            siz[u] += siz[v];
        }
    };

    dfs(0, 1, dfs);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = ans + (siz[i] - 1) % mod;
        if (i > 1) ans = (ans + siz[i] * (n - siz[i]) % mod) % mod;
        ans = (ans - (dep[i] * (dep[i] - 1) / 2) % mod + mod) % mod;
    }

    cout << ans << '\n';
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}