#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

void solve ()
{
    int n, m;
    cin >> n >> m;
    using arr2 = array <int, 2>;
    vector <vector <arr2> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    vector <int> cnt(n + 1);
    vector <int> mx(n + 1, -1);
    vector <int> mn(n + 1, 1e18);
    vector <int> dis(n + 1, 1e18);
    priority_queue <arr2, vector <arr2>, greater <arr2> > pq;

    cnt[1] = 1;
    mx[1] = 0;
    mn[1] = 0;
    dis[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist > dis[u]) continue;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dist + w) {
                dis[v] = dist + w;
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;
                cnt[v] = cnt[u];
                pq.push({dis[v], v});
            }else if (dis[v] == dist + w) {
                cnt[v] = (cnt[v] + cnt[u]) % mod;
                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            }
        }
    }

    cout << dis[n] << ' ' << cnt[n] << ' ' << mn[n] << ' ' << mx[n] << '\n';
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