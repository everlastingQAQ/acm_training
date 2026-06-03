#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    int s, t, p;
    cin >> s >> t >> p;
    using arr2 = array <int, 2>;
    vector <vector <arr2> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    vector <int> val(n + 1, 1e18);
    
    priority_queue <arr2, vector <arr2>, greater <arr2> > pq;
    pq.push({0, p});
    val[p] = 0;
    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist > val[u]) continue;
        for (auto [v, w] : e[u]) {
            if (val[v] > dist + w) {
                val[v] = dist + w;
                pq.push({val[v], v});
            }
        }
    }

    vector <int> dp(n + 1, 1e18);
    dp[s] = val[s];
    dp = val;
    vector <int> vis(n + 1, 0);
    vis[s] = true;

    priority_queue <arr2, vector <arr2>, less <arr2> > q;
    q.push({val[s], s});

    while (!q.empty()) {
        auto [vv, u] = q.top();
        q.pop();
        if (vv < dp[u]) continue;
        for (auto [v, w] : e[u]) {
            if (!vis[v]) {
                dp[v] = min(val[v], vv);
                q.push({dp[v], v});
                vis[v] = true;
            }else if (dp[v] < min(val[v], vv)) {
                dp[v] = min(val[v], vv);
                q.push({dp[v], v});
            }
        }
    }

    if (dp[t] == 1e18) {
        cout << "INF";
    }else {
        cout << dp[t] << '\n';
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