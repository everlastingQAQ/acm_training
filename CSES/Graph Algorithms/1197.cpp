#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <array <int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }

    queue <int> q;
    vector <int> dis(n + 1, 0);
    vector <int> vis(n + 1);
    vector <int> cnt(n + 1);
    vector <int> pre(n + 1);
    
    for (int i = 1; i <= n; i++) {
        q.push(i);
        vis[i] = true;
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pre[v] = u;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) {
                    for (int i = 1; i <= n; i++) {
                        v = pre[v];
                    }
                    int cur = v;
                    vector <int> ans;
                    do {
                        ans.push_back(cur);
                        cur = pre[cur];
                    }while (cur != v);
                    ans.push_back(v);
                    reverse(ans.begin(), ans.end());
                    cout << "YES\n";
                    for (auto x : ans) {
                        cout << x << ' ';
                    }
                    return;
                }
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    cout << "NO\n";
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