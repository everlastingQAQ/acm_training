#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        e[i].push_back(v);
        ind[v]++;
    }

    queue <int> q;
    vector <int> a;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            q.push(i);
        }
    }
    
    while (q.size()) {
        int u = q.front();
        q.pop();
        a.push_back(u);
        for (auto v : e[u]) {
            if (!(--ind[v])) q.push(v);
        }
    }

    cout << n - a.size() << '\n';
    
}   
    
signed main ()
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