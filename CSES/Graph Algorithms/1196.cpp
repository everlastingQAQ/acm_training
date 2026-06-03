#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    using arr2 = array <int, 2>;
    vector <vector <arr2> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }

    vector <int> ans;
    priority_queue <arr2, vector <arr2>, greater<arr2> > pq;
    pq.push({0, 1});
    vector <int> cnt(n + 1, 0);

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (++cnt[u] > k) continue;
        if (u == n) {
            ans.push_back(dist);
        }
        for (auto [v, w] : e[u]) {
            if (cnt[v] < k) {
                pq.push({dist + w, v});
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
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