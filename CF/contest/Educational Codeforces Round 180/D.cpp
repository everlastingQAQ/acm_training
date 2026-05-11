#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }

    int t = 1;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 2) {
            t = i;
            ok = true;
            break;
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }else {
        cout << "YES\n";
    }

    vector <array <int, 2> > ans;
    auto dfs1 = [&] (auto self, int u, int fa, int op) -> void {
        if (u == t) {
            op ^= 1;
        }
        for (auto v : e[u]) {
            if (v == fa) continue;
            if (op == 1) ans.push_back({u, v});
            else ans.push_back({v, u});
            self(self, v, u, op ^ 1);
        }
    };
    if (1 == t) dfs1(dfs1, 2, 0, 0);
    else dfs1(dfs1, 1, 0, 0);

    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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