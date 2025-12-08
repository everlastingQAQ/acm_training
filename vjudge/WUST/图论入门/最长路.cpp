#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m;
ll sum = 0;
vector <vector<pair<ll, ll> > > e(1500 + 1, vector <pair<ll, ll> > (1500 + 1));
vector <ll> ans(1500 + 1);
vector <bool> vis(1500 + 1, false);

void dfs (ll p, ll i)
{
    vis[p] = true;
    sum += e[i][]
    ans[i] = max(ans[i], )

}

void solve ()
{
    cin >> n >> m;
    

    for (int i = 1; i <= n; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    

    for (int i = 1; i <= n; i++) {
        vis.assign(n + 1, false);
        dfs(i, i);
    }

}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _; 
    while (_--) {
        solve();
    }
    return 0;
}