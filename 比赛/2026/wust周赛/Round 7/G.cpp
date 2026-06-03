#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> val(n + 50);
    vector <vector <array <int, 2> > > e(n + 50);
    for (int i = 32; i < 32 + n; i++) {
        cin >> val[i];
        for (int j = 0; j < 32; j++) {
            if (val[i] >> j & 1) {
                e[j].push_back({i, val[i]});
                e[i].push_back({j, val[i]});
            }
        }
    }

    vector <int> dis(n + 50, 1e18);
    priority_queue <array<int, 2>, vector <array<int, 2> > , greater<array<int, 2> > > pq;

    pq.push({0, 32});
    dis[32] = 0;
    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist > dis[u]) continue;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    for (int i = 32; i < 32 + n; i++) {
        cout << (dis[i] == 1e18 ? -1 : dis[i]) << ' ';
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