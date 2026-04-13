#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
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

    i64 ans = 0;
    vector <i64> cnt(n + 1, 1);

    auto dfs = [&] (auto self, int fa, int u) -> void {
        for (auto v : e[u]) {
            if (v == fa) continue;
            if (val[v] == val[u]) {
                cnt[v] = cnt[u] + 1;
            }else {
                cnt[v] = 1;
            }
            self(self, u, v);
        }
        ans += cnt[u] - 1;
    };
    dfs(dfs, 0, 1);

    cout << ans << '\n';
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