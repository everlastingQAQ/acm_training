#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int qpow (int a, int b)//a的b次方
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    int n; cin >> n;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    auto dfs = [&] (int fa, int u, int t, int cnt, auto self) -> int {
        if (u != 1 && e[u].size() == 1) {
            return t * cnt % mod;
        }
        int sz = e[u].size();
        int p = 0;
        for (auto v : e[u]) {
            if (v == fa) {
                p = (p + t * qpow(sz, mod - 2) % mod * cnt % mod) % mod;
                continue;
            }
            p = (self(u, v, t * qpow(sz, mod - 2) % mod, cnt + 1, self) + p) % mod;
        }
        return p % mod;
    };

    int ans = dfs(0, 1, 1, 1, dfs);

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