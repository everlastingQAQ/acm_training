#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <i64> num(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    vector <vector <array <i64, 2> > > e(n + 1);
    for (int i = 1; i <= m; i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    priority_queue <array <i64, 2>, vector <array <i64, 2> >, greater <array <i64, 2> > > pq;

    for (int i = 1; i <= n; i++) {
        pq.push({num[i], i});
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != num[u]) continue;
        for (auto [v, w] : e[u]) {
            if (num[u] + w < num[v]) {
                num[v] = num[u] + w;
                pq.push({num[v], v});
            }
        }
    }

    vector <i64> dis(n + 1, 1e16);
    dis[1] = 0;

    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] != d) continue;
        for (auto [v, w] : e[u]) {
            if (dis[u] + w < dis[v] && dis[u] + w <= num[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    cout << (dis[n] == 1e16 ? "NO\n" : "YES\n");
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