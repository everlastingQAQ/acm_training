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

ll n, t;

void solve ()
{
    cin >> n >> t;
    vector <pair<ll, ll> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].se;
    }
    sort(v.begin(), v.end(), [] (auto &a1, auto &b1) {
        if (a1.fi != b1.fi) {
            return a1.fi < b1.fi;
        }else {
            return a1.se > b1.se;
        }
    });

    vector <pair<ll, ll> > mx(n);

    if (n >= 2) {
        ll mx2 = min(v[0].se, v[1].se);
        ll mxx = max(v[0].se, v[1].se);
        mx[0].fi = v[0].se;
        mx[0].se = 0;
        mx[1].fi = max(v[0].se, v[1].se);
        mx[1].se = min(v[0].se, v[1].se);

        for (int i = 2; i < n; i++) {
            if (v[i].se > mxx) {
                mx2 = mxx;
                mxx = v[i].se;
            }else if (v[i].se == mxx) {
                mx2 = mxx;
            }else if (v[i].se < mxx && v[i].se > mx2) {
                mx2 = v[i].se;
            }
            mx[i].fi = mxx;
            mx[i].se = mx2;
        }  
    }else if (n == 1) {
        mx[0].fi = v[0].se;
        mx[0].se = 0;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << mx[i].fi << ' ' << mx[i].se << '\n';
    // }

    ll ans = 0;
    while (t--) {
        ll a;
        cin >> a;
        ll pos = lower_bound(v.begin(), v.end(), make_pair(a, 0LL), 
        [] (auto &a1, auto &b1) {
            return a1.fi < b1.fi;
        }) - v.begin() - 1;
        if (pos < 0) {
            continue;
        }
        // cout << pos << '\n';
        ans += mx[pos].fi;
        ans += mx[pos].se;
        // cout << mx[pos].fi << ' ' << mx[pos].se << '\n';
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