#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int w;
    cin >> w;
    vector <string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }

    
}

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}