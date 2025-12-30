#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

#define fi first
#define se second

const int N = 3e5;
const double eps = 1e-5;
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
    if (n < m) return 0;
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n); 
    map <ll, ll> mp;
    for (ll &x : v) {
        cin >> x;  
        mp[x]++; 
    }    
    
    ll cnt = 0, cnt4 = 0;
    vector <ll> a;

    for (auto [x, y] : mp) {
        if (y == 2) cnt++;
        else if (y >= 3 && y < 4) cnt++, a.push_back(x);
        else if (y >= 4) cnt++, cnt4++, a.push_back(x);
    }

    ll ans = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] != a[i + 1] - 1) continue;
        
    }
    cout << ans << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;

    f[0] = 1, g[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }

    while (_--) {
        solve();
    }
    return 0;
}   