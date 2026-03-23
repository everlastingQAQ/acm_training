#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }

    deque <int> q;
    vector <int> dist(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 1) {
            q.push_back(i);
            dist[i] = 0;
        }
    }

    int mx = 0;

    while (q.size()) {
        int u = q.front();
        q.pop_front();
        for (auto v : e[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                mx = max(mx, dist[v]);
                q.push_back(v);
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == mx) {
            cnt++;
        }
    }
    cout << cnt << '\n';

    for (int i = 1; i <= n; i++) {
        if (dist[i] == mx) {
            cout << i << ' ';
        }
    }

    cout << '\n';
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