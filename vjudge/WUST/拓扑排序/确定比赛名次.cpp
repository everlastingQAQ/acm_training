#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, m;
    while (cin >> n >> m) {
        vector <vector <int> > e(n + 1);
        vector <int> ind(n + 1);
        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            e[u].push_back(v);
            ind[v]++;
        }
        priority_queue <int, vector <int>, greater<int> > q;
        for (int i = 1; i <= n; i++) {
            if (ind[i] == 0) q.push(i);
        }

        vector <int> ans;
        while (q.size()) {
            int u = q.top();
            q.pop();
            ans.push_back(u);
            for (auto v : e[u]) {
                if (--ind[v] == 0) q.push(v);
            }
        }

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