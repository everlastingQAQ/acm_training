#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m; cin >> n >> m;
    vector <vector <int> > e(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        int cur = n - e[i].size() - 1;
        int ans = cur * (cur - 1) * (cur - 2) / 3 / 2;
        cout << ans << ' ';
    }
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