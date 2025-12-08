#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

ll n;
ll mx = 0, mxnode = 0;
vector <vector <ll> > e(1e5 + 5);

void dfs (ll node, ll fa, ll dep)
{
    if (dep > mx) {
        mx = dep;
        mxnode = node;
    }
    for (ll i : e[node]) {
        if (i == fa) continue;
        dfs(i, node, dep + 1);
    }
}

void solve ()
{
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 0, 0);
    
    mx = 0;
    dfs(mxnode, 0, 0);
    cout << mx << '\n';
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