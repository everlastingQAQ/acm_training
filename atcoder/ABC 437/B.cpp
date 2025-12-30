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
    ll n, m, q; cin >> n >> m >> q;
    vector <vector <ll> > v(n + 1, vector <ll> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    map <ll, bool> mp;
    for (int i = 0 ; i < q; i++) {
        ll t; cin >> t;
        mp[t] = true;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll mx = 0;
        for (int j = 1; j <= m; j++) {
            mx += mp[v[i][j]];
        }
        ans = max(ans, mx); 
    }

    cout << ans << '\n';    
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