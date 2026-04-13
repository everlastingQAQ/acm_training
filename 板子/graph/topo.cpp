#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > e(n + 5);
    vector <int> ind(n + 5, 0);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        ind[v]++;
    }

    queue <int> q;
    vector<int> tpsort;

    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            q.push(i);
        }
    }

    if (q.empty()) {
        cout << -1 << '\n';
        return;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        tpsort.push_back(u);
        for (int v : e[u]) {
            ind[v]--;
            if (!ind[v]) {
                q.push(v);
            }
        }
    }

    if (tpsort.size() != n) {
        cout << -1 << '\n';
        return;
    }

    for (int x : tpsort) {
        cout << x << ' ';
    }
    cout << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 
