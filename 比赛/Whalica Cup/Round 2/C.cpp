#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector <int> dep(n + 1);
    dep[0] = 0;
    int mxdep = 0;

    auto dfs1 = [&] (auto self, int u, int fa) -> void {
        dep[u] = dep[fa] + 1;
        mxdep = max(mxdep, dep[u]);
        for (int v : e[u]) {
            if (v == fa) continue;
            self(self, v, u);
        }                           
    };

    dfs1(dfs1, 1, 0);
    vector <int> val(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, t;
        cin >> u >> t;
        if (mxdep - t <= dep[u]) {
            val[u]++;
        } 
    }   

    vector <int> a(n + 1, 0);
    auto dfs2 = [&] (auto self, int u, int fa) -> void {
        int mx = 0;
        for (int v : e[u]) {
            if (v == fa) continue;
            self(self, v, u);
            mx = max(mx, a[v]);
        }
        a[u] = mx + val[u];
    };

    dfs2(dfs2, 1, 0);

    vector <int> b(mxdep + 1);
    for (int i = 1; i <= n; i++) {
        b[dep[i]]= max(b[dep[i]], a[i]);
    }

    vector <int> mx(n + 1, 0);
    auto dfs3 = [&] (auto self, int u, int fa, int sum) -> void {
        sum += val[u];
        mx[dep[u]] = max(mx[dep[u]], sum);
        for (int v : e[u]) {
            if (v == fa) continue;
            self(self, v, u, sum);
        }
    };

    dfs3(dfs3, 1, 0, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i] + mx[dep[i] - 1]);
    }

    cout << ans << '\n';
}
    
int32_t main ()
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/