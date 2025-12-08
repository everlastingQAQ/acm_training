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
    vector <pair<ll, ll> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].fi;
        v[i].se = i;
    }
    
    ll p = v[9].fi;
    ld t = m * 0.8;
    if (v[9].fi >= t) {
        cout << "Yes" << '\n';
        return;
    }

    sort(v.begin() + 1, v.end(), [] (auto a1, auto b1) {
        return a1.fi > b1.fi;
    });

    for (int i = 1; i <= 2; i++) {
        if (v[i].se == 9) {
            cout << "Yes" << '\n';
            return;
        }
    }

    ll i = 3;
    if (v[i].se == 9) {
        cout << "Yes" << '\n';
        return; 
    }
    while (v[i].fi == v[i + 1].fi) {
        i++;
        if (v[i].se == 9) {
            cout << "Yes" << '\n';
            return; 
        }
    }

    cout << "No" << '\n';

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