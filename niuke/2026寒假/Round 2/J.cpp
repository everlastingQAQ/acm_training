#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }

    map <int, vector <int> > mp;
    
    for (int i = 1; i <= n; i++) {
        mp[ind[i]].push_back(i);
    }

    vector <int> ans(n + 1, 1e14);
    vector <int> dis(n + 1, 1e14);

    for (auto [x, y] : mp | views::reverse) {
        queue <int> q;
        for (auto u : y) {
            q.push(u);
            if (dis[u] == 1e14) ans[u] = -1;
            else ans[u] = dis[u];
            dis[u] = 0;
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto v : e[u]) {
                if (ind[v] >= x) continue;
                if (dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                } 
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/