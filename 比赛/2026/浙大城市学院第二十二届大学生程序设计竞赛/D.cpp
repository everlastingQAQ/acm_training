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

ll qpow (ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    ll m, k; cin >> m >> k;
    ll t = m * k - 1;
    t %= mod;
    ll ans = ((t * (t + 1) % mod * (t + 2) % mod) % mod * qpow(3, mod - 2) % mod * qpow(2, mod - 2) % mod + t) % mod + 2;
    cout << ans % mod << '\n';
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