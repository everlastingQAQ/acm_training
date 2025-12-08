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
const ll inf = LLONG_MAX;

ll n, q;

void solve ()
{
    cin >> n >> q;
    vector <ll> v(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <ll> a(n + 1);
    vector <ll> b(n + 1);
    vector <ll> c(n + 1);

    for (ll i = 1; i <= n; i++) {
        a[i] = i * i * v[i] + a[i - 1];
        b[i] = i * v[i] + b[i - 1];
        c[i] = v[i] + c[i - 1];
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll ans = -(a[r] - a[l - 1]) + (l + r) * (b[r] - b[l - 1]) + (r - l - r * l + 1) * (c[r] - c[l - 1]);
        cout << ans << '\n';
    }
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