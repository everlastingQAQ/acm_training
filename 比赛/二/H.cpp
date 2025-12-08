#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, k;

void solve ()
{
    cin >> n >> k;

    vector <pair<ld, ll> > v(n + 1);

    ll a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        v[i].fi = 1.0L * a / b;
        v[i].se = i;
    }

    sort(v.begin() + 1, v.end(), [] (auto &a1, auto &b1) {
        return a1.fi < b1.fi;
    });

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].fi <= v[n - k].fi) {
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