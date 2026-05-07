#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;
const int N = 1e6;
i64 f[N], g[N];

i64 qpow (i64 a, i64 b)
{
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    int n;
    cin >> n;
    vector <i64> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    vector <i64> a(n + 1), b(n + 1);
    a[1] = val[1];
    b[1] = val[1];
    auto dfs = [&] (auto self, int fa, int u) -> void {
        i64 mx = val[u];
        i64 mn = val[u];
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
            mx = max(mx, b[v]);
            mn = min(mn, a[v]);
        }
        a[u] = mn;
        b[u] = mx;
    };
    dfs(dfs, 0, 1);

    i64 ans = 1;
    bool ok = true;
    auto dfs2 = [&] (auto self, int fa, int u) -> void {
        vector <array <i64, 2> > c;
        for (auto v : e[u]) {
            if (v == fa) continue;
            c.push_back({a[v], b[v]});
        }
        sort(c.begin(), c.end());
        i64 cur = val[u];
        map <i64, int> mp;
        for (auto [x, y] : c) {
            if (x < cur) {
                ok = false;
                return;
            }
            cur = y;
            if (x == y) mp[x]++;
        }
        
        for (int i = 0; i < c.size(); i++) {
            int j = i;
            while (j < c.size() && c[i][0] == c[j][0] && c[i][1] == c[j][1]) {
                j++;
            }
            int cnt = j - i;
            ans = ans * f[cnt] % mod;
            i = j - 1;
        }
        
        ans = ans * g[c.size()] % mod;

        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
            if (!ok) return;
        }

    };
    dfs2(dfs2, 0, 1);

    if (!ok) {
        cout << 0 << '\n';
        return;
    }

    cout << ans << '\n';
}

void init ()
{
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    g[N - 1] = qpow(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        g[i] = g[i + 1] * (i + 1) % mod;
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}