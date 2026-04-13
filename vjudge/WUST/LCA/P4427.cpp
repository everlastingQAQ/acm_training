#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;

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
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector <int> dep(n + 1);
    vector <int> fa(n + 1);
    vector <array <int, 51> > pre(n + 1);
    dep[0] = -1;
    fa[1] = 0;

    auto dfs = [&] (auto self, int f, int u) -> void {
        dep[u] = dep[f] + 1;
        i64 cur = 1;
        for (int i = 1; i <= 50; i++) { 
            pre[u][i] = pre[f][i];
            cur = cur * dep[u] % mod;
            pre[u][i] = (pre[u][i] + cur) % mod;
        }
        fa[u] = f;

        for (auto v : e[u]) {
            if (v == f) continue;
            self(self, u, v);
        }
    };
    dfs(dfs, 0, 1);

    int m = __lg(n);
    vector <vector <int> > st(n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i++) {
        st[i][0] = fa[i];
    }
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= n; i++) {
            st[i][k] = st[st[i][k - 1]][k - 1];
        }
    }

    auto lca = [&] (int u, int v) -> int {
        if (dep[u] < dep[v]) swap(u, v);
        if (dep[u] > dep[v]) {
            for (int k = m; k >= 0; k--) {
                if (dep[st[u][k]] >= dep[v]) {
                    u = st[u][k];
                }
            }
        }

        if (u == v) return u;

        for (int k = m; k >= 0; k--) {
            if (st[u][k] != st[v][k]) {
                u = st[u][k];
                v = st[v][k];
            }
        }

        return fa[u];
    };

    int q;
    cin >> q;
    while (q--) {
        int u, v, x;
        cin >> u >> v >> x;
        int t = lca(u, v);
        i64 res = (((pre[u][x] + pre[v][x]) % mod - 2 * pre[t][x] % mod + mod) % mod + qpow(dep[t], x)) % mod;
        cout << res << '\n';
    }
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}