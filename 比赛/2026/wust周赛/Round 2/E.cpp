#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	i64 n, r, m;
    cin >> n >> r >> m;
    vector <vector <i64> > e(n + 1);
    vector <int> ind(n + 1);
    vector <int> dep(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }

    int mx = 1;
    dep[r] = 1;
    vector <int> fa(n + 1);

    auto dfs1 = [&] (auto self, int f, int u) -> void {
        fa[u] = f;
        for (auto v : e[u]) {
            if (v == f) continue;
            dep[v] = dep[u] + 1;
            mx = max(dep[v], mx);
            self(self, u, v);
        }
    };
    dfs1(dfs1, 0, r);

    vector <vector <int> > t(mx + 1);
    for (int i = 1; i <= n; i++) {
        t[dep[i]].push_back(i);
    }
    
    vector <i64> val(n + 1, 1);
    for (int i = mx; i >= 1; i--) {
        for (auto u : t[i]) {
            val[u] = 1;
            for (auto v : e[u]) {
                if (v == fa[u]) continue;
                val[u] += val[v];
            }
        }
    }
        
    vector <i64> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        vector <i64> a;
        a.reserve(n + 1);
        for (auto v : e[i]) {
            if (v == fa[i]) continue;
            a.push_back(val[v]);
        }
        i64 cur = (val[i] - 1) * 2 + 1;
        for (int j = 0; j < a.size(); j++) {
            for (int k = j + 1; k < a.size(); k++) {
                cur += a[j] * a[k] * 2;
            }
        }
        ans[i] = cur;
    }
    
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
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
