#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int m = 20;

void solve ()
{
    int n, q;
    cin >> n >> q;
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

    vector <int> fa(n + 1);
    vector <int> order;
    order.reserve(n + 1);
    fa[1] = 0;
    
    auto dfs = [&] (auto self, int f, int u) -> void {
        order.push_back(u);
        fa[u] = f;
        for (auto v : e[u]) {
            if (v == f) continue;
            self(self, u, v);
        }
    };
    dfs(dfs, 0, 1);

    vector <array <int, m> > st(n + 1);
    for (auto u : order) {
        st[u].fill(0);
        st[u][0] = fa[u];
    }
    for (int k = 1; k < m; k++) {
        for (int i = 1; i <= n; i++) {
            st[i][k] = st[st[i][k - 1]][k - 1];
        }
    }

    vector <multiset <i64> > a(n + 1);
    for (int i = 2; i <= n; i++) {
        a[fa[i]].insert(val[i]);
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u;
            i64 w;
            cin >> u >> w;
            if (val[u] >= w) {
                cout << u << '\n';
                continue;
            }
            int cur = u;
            for (int k = m - 1; k >= 0; k--) {
                int t = st[cur][k];
                if (t != 0 && val[t] < w) {
                    cur = t;
                }
            }
            if (fa[cur] == 0) {
                cout << -1 << '\n';
            }else {
                cout << fa[cur] << '\n';
            }
        }else {
            int x;
            i64 v;
            cin >> x >> v;
            bool ok = true;
            if (x != 1 && v + val[x] > val[fa[x]]) {
                ok = false;
            }
            if (ok && !a[x].empty()) {
                i64 mx = *a[x].rbegin();
                if (v + val[x] < mx) {
                    ok = false;
                }
            }
            if (!ok) {
                cout << "FAILED\n";
                continue;
            }
            if (x != 1) {
                a[fa[x]].erase(a[fa[x]].find(val[x]));
                a[fa[x]].insert(v + val[x]);
            }
            val[x] += v;
            cout << "SUCCESS\n";
        }
    }
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;	
	while (_--) {
		solve();
	}
	return 0;
}
