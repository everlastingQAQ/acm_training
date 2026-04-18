#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

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

    priority_queue <int, vector <int>, greater<int> > pq;
    vector <int> vis(n + 1);
    vector <int> ans;
    ans.reserve(n + 1);
    vis[1] = true;
    pq.push(1);

    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        ans.push_back(u);
        for (auto v : e[u]) {
            if (vis[v]) continue;
            pq.push(v);
            vis[v] = 1;
        }
    }

    for (auto x : ans) {
        cout << x << " \n"[x == ans.back()];
    }
}
 
int main ()
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