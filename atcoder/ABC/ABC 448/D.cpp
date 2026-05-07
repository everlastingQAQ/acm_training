#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> val(n + 1);
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

    set <int> st;
    vector <int> ok(n + 1, 0);
    auto dfs = [&] (auto self, int u, int fa) -> void {
        bool found = false;
        if (st.count(val[u])) found = true;

        if (found || ok[fa]) ok[u] = true;
        st.insert(val[u]);

        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, v, u);
        }
        if (!found) st.erase(val[u]);
    };
    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; i++) {
        cout << (ok[i] ? "Yes\n" : "No\n"); 
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