#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

ll qpow (ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    ll n, len; cin >> n >> len;
    ll tag = len;
    if (n <= 60) tag = min(qpow(2, n-1), len);

    for (int i = 0; i < tag; i++) {
        cout << 1;
    }
    for (int i = 0; i < len - tag; i++) {
        cout << (i & 1);
    }
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