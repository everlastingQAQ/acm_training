#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int mod = 100003;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <array <int, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, 1});
        e[v].push_back({u, 1});
    }
    vector <int> cnt(n + 1, 0);
    vector <int> dis(n + 1, 1e8);
    dis[1] = 0;
    cnt[1] = 1;
    priority_queue <array <int, 2>, vector <array <int, 2> >, greater <array <int, 2> > > pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dis[u] < dist) continue;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dist + w) {
                dis[v] = dist + w;
                cnt[v] = cnt[u];
                pq.push({dis[v], v});
            }else if (dis[v] == dist + w) {
                cnt[v] = (cnt[v] + cnt[u]) % mod;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << '\n';
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