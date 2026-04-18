#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <vector <int> > e(n + 1);
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        e[u].push_back(i);
        e[i].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!e[i].empty()) sort(e[i].begin(), e[i].end());
    }

    vector <int> a;
    vector <int> sz(n + 1, 1);
    vector <int> id(n + 1);
    auto dfs = [&] (auto self, int fa, int u) -> void {
        a.push_back(u);
        int cur = 0;
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
            cur += sz[v];
        }
        sz[u] = cur + 1;
    };
    dfs(dfs, 0, 1);

    for (int i = 0; i < n; i++) {
        id[a[i]] = i;
    }

    while (q--) {
        int u, k;
        cin >> u >> k;
        if (k > sz[u]) {
            cout << -1 << '\n';
            continue;
        }
        cout << a[id[u] + k - 1] << '\n';
    }
}

int main ()
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