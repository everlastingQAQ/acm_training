#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int N = 1e6 + 10;
const double eps = 1e-12;
const ll mod = 998244353;

ll f[N], g[N];

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

ll C (ll n, ll m)
{
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void init()
{
    f[0] = 1, g[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }
}

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1);
    ll sum = 0;
    for (int i = 0; i <= n; i++) cin >> v[i], sum += v[i];

    if (sum == 0) {
        cout << f[n] << '\n';
        return;
    }

    ll mx = *max_element(v.begin() + 1, v.end());
    ll cntmx = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == mx) cntmx++;
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += max(0LL, mx - 1 - v[i]);
    }

    // cout << cnt << '\n';
    ll t = v[0] - cnt;
    // cout << t << '\n';
    if (t < 0) {
        cout << 0 << '\n';
        return;
    }else if (t >= n - cntmx) {
        cout << f[n] << '\n';
        return;
    }

    // cout << cntmx << '\n';
    ll ans = f[cntmx + t] * f[n - cntmx - t] % mod;
    ans = (ans * C(n - cntmx, t)) % mod;   

    cout << ans << '\n';

}   
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}   