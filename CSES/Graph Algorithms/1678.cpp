#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ind[v]++;
        e[u].push_back(v);
    }

    queue <int> q;
    vector <int> vis(n + 1, 0);
    vector <int> ans;
    auto dfs = [&] (auto self, int u, int v) -> void {

    };

    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
}     

int32_t main ()
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