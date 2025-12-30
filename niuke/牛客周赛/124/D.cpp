#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <vector <ll> > e(n + 1);
    for (int i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (e[i].size() == 1) {
            cnt++;
        }
    }

    cout << (cnt + 1) / 2 << '\n';
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