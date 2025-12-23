#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

#define fi first
#define se second

const int N = 3e5;
const double eps = 1e-5;
const ll mod = 998244353;

void solve ()
{
    ll n, m; cin >> n >> m;
    vector <vector <ll> > e(n + 1);
    for (int i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        e[v].push_back(u);
    }
    ll q; cin >> q;
    vector <bool> vis(n + 1, false);

    auto dfs = [&] (ll u, auto self) -> void {
        if (vis[u]) return;
        vis[u] = true;
        for (int v : e[u]) {
            self(v, self);
        }
    };

    while (q--) {
        ll a, v; cin >> a >> v;
        if (a == 1) {
            dfs(v, dfs);
        }else {
            cout << (vis[v] ? "Yes" : "No") << '\n';
        }
    }
}

int main ()
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