#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    cin >> n;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while (x--) {
            int t;
            cin >> t;
            e[i].push_back(t);
        }
    }

    vector <int> dep(n + 1);
    vector <int> fa(n + 1);
    dep[1] = 1;
    fa[1] = 0;

    auto dfs = [&] (auto self, int f, int u) -> void {
        fa[u] = f;
        for (auto v : e[u]) {
            if (v == f) continue;
            dep[v] = dep[u] + 1;
            self(self, u, v);
        }
    };
    dfs(dfs, 0, 1);

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

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dep[u] < dep[v]) swap(u, v);
        if (dep[u] > dep[v]) {
            for (int k = m; k >= 0; k--) {
                if (dep[st[u][k]] >= dep[v]) {
                    u = st[u][k];
                }
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
    int cnt = 1;
    cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
	return 0;
}