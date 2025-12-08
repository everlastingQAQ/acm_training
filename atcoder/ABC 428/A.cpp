#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll s, a, b, x;

void solve ()
{
    cin >> s >> a >> b >> x;
    ll t = x / (a + b);
    ll tt = x % (a + b);
    ll xx = a * s;
    ll ans = xx * t;
    if (tt >= a) {
        ans += xx;
    }else {
        ans += s * tt;
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