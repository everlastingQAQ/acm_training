#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, s, t;
    cin >> n >> s >> t;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }

    deque <int> ans;
    queue <int> q;
    vector <int> vis(n + 1);
    vis[t] = true;
    q.push(t);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_front(u);
        for (auto v : e[u]) {
            if (vis[v]) continue;
            q.push(v);
            vis[v] = true;
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
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}