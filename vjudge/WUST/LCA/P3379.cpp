#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n, q, s;
    cin >> n >> q >> s;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector <int> fa(n + 1);
    vector <int> dep(n + 1);
    fa[s] = 0;
    dep[s] = 1;

    auto dfs = [&] (auto self, int f, int u) -> void {
        fa[u] = f;
        for (auto v : e[u]) {
            if (v == f) continue;
            dep[v] = dep[u] + 1;
            self(self, u, v);
        }
    };
    dfs(dfs, 0, s);

    int m = __lg(n);
    vector <vector <int> > st(n + 1, vector <int> (m + 1)); 
    for (int i = 1; i <= n; i++) {
        fill(st[i].begin(), st[i].end(), 0);
        st[i][0] = fa[i]; 
    }
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= n; i++) {
            st[i][k] = st[st[i][k - 1]][k - 1];
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        if (dep[u] < dep[v]) swap(u, v);
        for (int k = m; k >= 0; k--) {
            if (dep[st[u][k]] >= dep[v]) {
                u = st[u][k];
            }
        }

        if (u == v) {
            cout << u << '\n';
            continue;
        }
        for (int k = m; k >= 0; k--) {
            if (st[u][k] != st[v][k]) {
                u = st[u][k];
                v = st[v][k];
            }
        }

        cout << fa[u] << '\n';
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