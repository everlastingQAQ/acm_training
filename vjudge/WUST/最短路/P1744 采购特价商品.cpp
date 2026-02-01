#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, m; cin >> n >> m;
    vector <vector <array<int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
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