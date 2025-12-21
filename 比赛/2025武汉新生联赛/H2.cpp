#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 1e6 + 10;
const double eps = 1e-5;
const ll mod = 998244353;

vector <ll> f(MAXN), g(MAXN);

ll qpow (ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

ll C (ll n, ll m)
{
    if (m < 0 || m > n) return 0;
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void solve ()
{
    ll n, k, m, q; cin >> n >> k >> m >> q;
    ll a = 0, b = 0;
    for (int i = 0; i <= min(k, m); i++) {
        a = (a + C(k, i) * C(n - k, m - i) % mod * (k - i) % mod) % mod;
        b = (b + C(k, i) * C(n - k, m - i) % mod) % mod;
    }
    ll ans = a * qpow(b, mod - 2) % mod;
    cout << ans << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;

    f[0] = 1, g[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }

    while (_--) {
        solve();
    }
    return 0;
}   