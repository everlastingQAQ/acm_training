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
    
    vector <pair<ll, ll> > v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i].fi;
        v[i].se = i;
    }

    sort(v.begin() + 1, v.end(), [] (auto &a1, auto &b1) {
        return a1.fi < b1.fi;
    });

    vector <ll> pos(n + 1);

    for (int i = 1; i <= n; i++) {
        pos[v[i].se] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << pos[i] << ' ';
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