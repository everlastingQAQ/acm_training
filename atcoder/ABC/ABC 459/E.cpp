#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

int qpow (int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int C (int a, int b) {
    int res = 1;
    for (int i = 1; i <= b; i++) {
        res = res * ((a - i + 1) % mod) % mod * qpow(i, mod - 2) % mod;
    }
    return res;
}

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > e(n + 1);
    vector <int> fa(n + 1);
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        fa[i] = u;
        e[i].push_back(u);
        e[u].push_back(i);
    }
    vector <int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    vector <int> nd(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nd[i];
    }

    vector <int> dep(n + 1);
    vector <vector <int> > a(n + 1);
    dep[1] = 1;
    int mx = 1;
    a[1].push_back(1);
    auto dfs1 = [&] (auto self, int f, int u) -> void {
        for (auto v : e[u]) {
            if (v == f) continue;
            dep[v] = dep[u] + 1;
            a[dep[v]].push_back(v);
            mx = max(mx, dep[v]);
            self(self, u, v);
        }
    };
    dfs1(dfs1, 0, 1);

    vector <int> lft;
    lft = val;
    int ans = 1;
    bool ok = true;
    for (int i = mx; i >= 1; i--) {
        for (auto u : a[i]) {
            if (nd[u] > lft[u]) {
                ok = false;
                break;
            }
            ans = ans * C(lft[u], nd[u]) % mod;
            lft[u] -= nd[u];
            lft[fa[u]] += lft[u];
        }
        if (!ok) break;
    }

    if (!ok) {
        cout << 0 << '\n';
    }else {
        cout << ans % mod << '\n';
    }
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