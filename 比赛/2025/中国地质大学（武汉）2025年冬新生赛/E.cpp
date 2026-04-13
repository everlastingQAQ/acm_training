#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    vector <pair<ll, ll> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }
    sort(v.begin(), v.end(), [] (auto &a1, auto &b1) {
        if (a1.fi - a1.se != b1.fi - b1.se) {
            return a1.fi - a1.se < b1.fi - b1.se;
        }else {
            return a1.fi < b1.fi;
        }
    });

    ll ans = 0;
    for (int i = 1; i <= v[0].se; i++) {
        ans += i;
    }
    ll t = v[0].fi;
    ll m = v[0].se;

    for (int i = 1; i < n; i++) {
        if (v[i].fi < t) {
            continue;
        }
        
        for (int j = 0; j < v[i].fi - t; j++) {
            if (m <= 0) {
                break;
            }
            ans += m;
            m--;
        }

        if (i == n - 1) {
            break;
        }

        if (v[i].se > v[i + 1].se) {
            m = v[i + 1].se;
            for (int i = 0; i < )
        }
        ll u = (v[i + 1].fi - v[i + 1].se + 1) - (v[i].fi + v[i].se - 1);
        if (u > 0) {
            ll b = v[i].se - 1;
            for (int k = 0; k < u; k++) {
                cout << ans << ' ' << b << '\n';
                if (b <= 0) {
                    break;
                }
                ans += b;
                b--;
            }
        }  
        t = max(t, v[i].fi);
        m = v[i].se;
    }

    for (int i = 1; i < v[n - 1].se; i++) {
        ans += i;
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