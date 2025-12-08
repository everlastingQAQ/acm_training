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
        return a1.se < b1.se;
    });

    ll pos = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (pos <= v[i].fi) {
            pos = v[i].se;
            ans++;
        }
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