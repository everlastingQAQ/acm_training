#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    vector <vector <int> > vv(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i == r1) continue;
        int x;
        cin >> x;
        vv[x].push_back(i);
    }

    vector <vector <int> > e(n + 1);
    auto dfs1 = [&] (auto self, int u) -> void {
        for (auto x : vv[u]) {
            e[x].push_back(u);
            e[u].push_back(x);
            self(self, x);
        }
    };
    dfs1(dfs1, r1);

    vector <int> ans(n + 1);
    auto dfs2 = [&] (auto self, int fa, int u) -> void {
        ans[u] = fa;
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
        }
    };
    dfs2(dfs2, 0, r2);

    for (int i = 1; i <= n; i++) {
        if (i == r2) continue;
        cout << ans[i] << ' ';
    }
    cout << '\n';
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