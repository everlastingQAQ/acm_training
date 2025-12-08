#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
 
ll n, m;

void solve ()
{
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll p, q, w;
        cin >> p >> q >> w;
        ans += max(ceil(1.0 * m * p / q) - w, (double)0);
    }
    cout << ans << '\n';
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