#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m; cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e[v].push_back(u);
        ind[u]++;
    }
    priority_queue <int> pq;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) pq.push(i);
    }

    vector <int> ans;

    while (pq.size()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for (auto v : e[u]) {
            if (!(--ind[v])) pq.push(v);
        }
    }

    ranges::reverse(ans);
    if (ans.size() != n) {
        cout << "Impossible!" << '\n';
    }else {
        for (auto x : ans) cout << x << " \n"[x == ans.back()];
    }
}   
    
int32_t main ()
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