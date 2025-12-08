#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, q, t;

void solve ()
{
    cin >> n >> q;

    vector <pair<pair<ll, ll>, ll> > v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i].fi.fi >> v[i].fi.se;
        v[i].se = i;
    }

    sort(v.begin() + 1, v.end(), [](const pair<pair<ll, ll>, ll> &a1, const pair<pair<ll, ll>, ll> &b1) {
        return a1.fi.fi < b1.fi.fi;
    });

    vector<ll> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(v[i].fi.fi);
    }

    for (int i = 1; i <= q; i++) {
        cin >> t;
        ll pos = upper_bound(a.begin(), a.end(), t) - a.begin() - 1;
        if (pos >= 0 && t >= v[pos + 1].fi.fi && t <= v[pos + 1].fi.se) {
            cout << v[pos + 1].se << '\n';
        }else {
            cout << -1 << '\n';
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

