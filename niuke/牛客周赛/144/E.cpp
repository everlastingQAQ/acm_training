#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector <int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    vector <vector <array <int, 2> > > e(n + 1);
    vector <int> f(n + 1), h(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> f[i]; 
    }
    for (int i = 2; i <= n; i++) {
        cin >> h[i]; 
    }

    for (int i = 2; i <= n; i++) {
        e[f[i]].push_back({i, h[i]});
    }

    vector <int> ans(n + 1);
    int cur = 0;
    auto dfs = [&] (auto self, int u) -> void {
        sort(e[u].begin(), e[u].end(), [] (auto a, auto b) {
            return a[1] < b[1];
        });
        int pre = 0;
        for (auto [v, w] : e[u]) {
            cur += w - pre;
            pre = w;
            self(self, v);
        }
        cur += val[u] - pre;
        ans[u] = cur;
    };
    dfs(dfs, 1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int32_t main()
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