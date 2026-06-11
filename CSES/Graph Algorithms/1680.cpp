#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ind[v]++;
        e[u].push_back(v);
    }

    vector <int> val(n + 1, 0);
    val[1] = 1;
    using arr2 = array <int, 2>;
    priority_queue <arr2, vector <arr2>, greater<arr2> > pq;
    pq.push({1, 1});

    while (!pq.empty()) {
        auto [p, u] = pq.top();
        pq.pop();
        if (p != val[u]) continue;
        for (auto v : e[u]) {
            
        }
    }
    auto dfs = [&] (auto self, int u) -> void {
        for (auto v : e[u]) {
            if (val[v] == 0) {
                val[v] = val[u];
                self(self, v);
            }else {
                val[v] = 
            }
        }
    };
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