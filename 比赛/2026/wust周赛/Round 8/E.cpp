#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    using arr2 = array <int, 2>;
    vector <vector <arr2> > e1(n + 1), e2(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e1[u].push_back({v, w});
        e2[v].push_back({u, w});
    }

    int ans = 0;
    auto cal = [&] (vector <vector <arr2> > e) -> int {
        vector <int> dis(n + 1, 1e18);
        dis[1] = 0;
        priority_queue <arr2, vector <arr2>, greater<arr2> > pq;
        pq.push({0, 1});
        while (pq.size()) {
            auto [dist, u] = pq.top(); 
            pq.pop();
            if (dist != dis[u]) continue;
            for (auto [v, w] : e[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        int cur = 0;
        for (int i = 2; i <= n; i++) {
            cur += dis[i];
            // cout << dis[i] << '\n';
        }
        return cur;
    };
    ans += cal(e1);
    ans += cal(e2);

    cout << ans << '\n';
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