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

void solve ()
{   
    ll n, q; cin >> n >> q;
    vector <ll> v(n);
    ll mx = -1e11;
    for (ll &x : v) cin >> x, mx = max(mx, x);
    sort(v.begin(), v.end());
    ll t = 0;
    vector <pi> s(mx + 1, {0, 0});
    for (int i = 1; i <= mx; i++) {
        while (t < n && i == v[t]) {
            s[i].fi += v[t];
            t++;
            s[i].se++;
        }
        s[i].fi += s[i - 1].fi;
        s[i].se += s[i - 1].se;
    }

    while (q--) {
        ll x; cin >> x;
        if (x > mx) {
            cout << -1 << '\n';
        }else {
            cout << s[x - 1].fi + (n - s[x - 1].se) * (x - 1) + 1 << '\n';
        }
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