#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 80112002;

void solve ()
{
    int n, m; cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1, 0);
    vector <int> out(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        ind[v]++;
        out[u]++;
    }

    queue <int> q;
    vector <int> v(n + 1, 0);
    vector <int> a;

    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            q.push(i);
            v[i] = 1;
        }
        if (!out[i]) {
            a.push_back(i);
        }
    }

    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto x : e[u]) {
            v[x] = (v[x] + v[u]) % mod;
            if (!(--ind[x])) q.push(x);
        }
    }

    int ans = 0;
    for (auto x : a) {
        ans = (ans + v[x]) % mod;
    }

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