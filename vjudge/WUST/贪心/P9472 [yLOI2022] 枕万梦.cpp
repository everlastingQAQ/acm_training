#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m;

void solve ()
{
    cin >> n >> m;

    vector <pair<pair<ll, ll>, ll> > v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i].fi.fi;
        v[i].fi.se = v[i].fi.fi * i;
        v[i].se = i;
    }

    sort(v.begin() + 1, v.end(), [] (auto &a1 , auto &b1) {
        if (a1.fi.fi != b1.fi.fi) {
            return a1.fi.fi < b1.fi.fi;
        }else {
            return a1.fi.se < b1.fi.se;
        }
    });

    for (int i = 1; i <= n; i++) {
        cout << v[i].se << ' ';
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