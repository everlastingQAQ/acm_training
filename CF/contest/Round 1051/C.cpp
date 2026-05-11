#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <vector <ll> > e(n + 1);
    vector <ll> ind(n + 1, 0);
    for (int i = 1; i < n; i++) {
        ll u, v, x, y; cin >> u >> v >> x >> y;
        if (x > y) {
            e[v].push_back(u);
            ind[u]++;
        }else {
            e[u].push_back(v);
            ind[v]++;
        }
    }

    vector <ll> ans(n + 1);
    queue <ll> q;

    for (int i = 1; i <= n; i++) {
        if (!ind[i]) q.push(i);
    }

    ll t = 1;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        ans[u] = t++;

        for (ll v : e[u]) {
            if (--ind[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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