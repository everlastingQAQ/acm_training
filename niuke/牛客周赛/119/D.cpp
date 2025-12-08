#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
const ll inf = LLONG_MAX;

ll n, k;

void solve ()
{
    cin >> n >> k;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <ll> pos;
    for (int i = 0; i < 64; i++) {
        if ((k >> i) & 1) {
            pos.push_back(i);
        }
    }

    ll t = 0;
    ll mn = inf;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            t += v[i];
        }else {
            t -= v[i];
            mn = min(mn, t);
        }
    }

    ll ans = 0;

    auto qpow = [&] (ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };

    for (auto x : pos) {
        if (x + mn >= 0) {
            ll q = x + t;
            ans += qpow(2LL, q);
            ans %= mod;
        }
    }

    cout << ans % mod << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}