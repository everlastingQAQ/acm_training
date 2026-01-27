#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, m; cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        ind[v]++;
    }

    queue <array<int, 2> > q;
    vector <int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) q.push({i, 1});
    }

    while (q.size()) {
        auto [u, val] = q.front();
        q.pop();
        ans[u] = val;
        for (auto v : e[u]) {
            ind[v]--;
            if (ind[v] == 0) {
                q.push({v, val + 1});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}   
    
signed main ()
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