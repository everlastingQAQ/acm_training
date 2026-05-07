#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector <vector <int> > e1(n + 1);
    int m1;
    cin >> m1;
    map <array <int, 2> , int> mp1;
    for (int i = 1; i <= m1; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        mp1[{u, v}] = true;
        e1[u].push_back(v);
        e1[v].push_back(u);
    }
    int m2;
    cin >> m2;
    vector <vector <int> > e2(n + 1);
    map <int, int> mp2;
    bool ok = false;
    for (int i = 1; i <= m2; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        if (mp1[{u, v}]) {
            mp2[u] = true;
            mp2[v] = true;
            ok = true;
        }
        e2[u].push_back(v);
        e2[v].push_back(u);
    }

    if (!ok) {
        cout << -1 << '\n';
        return;
    }

    vector <vector <int> > dis(n + 1, vector <int> (n + 1, 1e8));
    priority_queue <array <int, 3>, vector <array <int, 3> >, greater<array <int, 3> > > pq;
    dis[s1][s2] = 0;
    pq.push({0, s1, s2});

    while (!pq.empty()) {
        auto [dist, u1, u2] = pq.top();
        pq.pop();
        if (dist != dis[u1][u2]) continue;
        for (auto v1 : e1[u1]) {
            for (auto v2 : e2[u2]) {
                int w = abs(v1 - v2);
                if (dis[v1][v2] > dist + w) {
                    dis[v1][v2] = dist + w;
                    pq.push({dis[v1][v2], v1, v2});
                }
            }
        }
    }
 
    int ans = 1e8;
    for (int i = 1; i <= n; i++) {
        if (mp2[i]) {
            ans = min(dis[i][i], ans);
        }
    }

    cout << (ans == 1e8 ? -1 : ans) << '\n';
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