#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 1e5 + 10;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;
vector<vector<ll> > e(MAXN);
vector<ll> dep(MAXN);
vector<ll> siz(MAXN);

void dfs(ll u, ll f)
{
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    for (auto x : e[u]) {
        if (x == f) continue;
        dfs(x, u);
        siz[u] += siz[x];
    }
}

void solve ()
{
    cin >> n;
    ll u, v;
    e.assign(n + 1, vector<ll>());
    dep.assign(n + 1, 0);
    siz.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << dep[i] << ' ' << n - siz[i] + 1 << '\n';
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