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
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        ind[v]++;
    }

    queue <int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) q.push(i);
    }

    vector <int> ans;

    while (q.size()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);

        for (auto v : e[x]) {
            ind[v]--;
            if (ind[v] == 0) q.push(v);
        }
    }

    if (ans.size() != n) {
        cout << -1 << '\n';
    }else {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
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