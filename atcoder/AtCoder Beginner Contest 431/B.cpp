#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll x, n, q;

void solve ()
{
    cin >> x >> n;

    vector <pair<ll, bool> > v(n + 1, {0, false});
    for (int i = 1; i <= n; i++) {
        cin >> v[i].fi;
    }

    cin >> q;

    ll t;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (v[t].se == false) {
            x += v[t].fi;
            v[t].se = true;
        }else {
            x -= v[t].fi;
            v[t].se = false;
        }
        cout << x << '\n';
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