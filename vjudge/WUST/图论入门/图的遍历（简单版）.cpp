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
vector <ll> ans(1005);
bool vis[1005];
vector <vector<ll> > e(1005);

void dfs (ll p, ll i)
{
    vis[p] = true;
    ans[i] = max(ans[i], p);

    for (auto x : e[p]) {
        if (!vis[x]) {
            dfs(x, i);
        }
    }
}

void solve ()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }

    
    for (ll i = 1; i <= n; i++) {
        memset(vis, false, sizeof(vis));
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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