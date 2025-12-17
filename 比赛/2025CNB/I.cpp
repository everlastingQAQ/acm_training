#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const ll MAXN = 1e7;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n;

void solve ()
{
    cin >> n;
    vector <pi> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }
    sort(v.begin(), v.end(), [] (auto a1, auto b1) {
        return abs(a1.fi - a1.se) < abs(b1.fi - b1.se);
    });

    ll ans = 0, maxfi = 0, maxse = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].fi > v[i].se) {
            ans = max(ans, maxse + v[i].se);
        }else {
            ans = max(ans, maxfi + v[i].fi);
        }
        maxfi = max(maxfi, v[i].fi);
        maxse = max(maxse, v[i].se);
    }

    cout << ans << '\n';
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