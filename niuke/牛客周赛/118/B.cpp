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

    ll mx1 = 0, mx2 = 0, my1 = 0, my2 = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((v[j].se - v[i].se) * (v[j].se - v[i].se) + (v[j].fi - v[i].fi) * (v[j].fi - v[i].fi) > (my1 - my2) * (my1 - my2) + (mx1 - mx2) * (mx1 - mx2)) {
                mx1 = v[j].fi;
                mx2 = v[i].fi;
                my1 = v[j].se;
                my2 = v[i].se;
            }
        }
    }

    cout << mx1 << ' ' << my1 << ' ' << mx2 << ' ' << my2 << '\n';
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