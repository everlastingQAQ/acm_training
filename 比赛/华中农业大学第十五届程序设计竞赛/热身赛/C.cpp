#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;
using pii = pair<pi, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n;

void solve ()
{
    cin >> n;
    vector <string> s(n);
    vector <pii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> v[i].fi.fi >> v[i].fi.se;
        v[i].se = i;
    }   

    sort(v.begin(), v.end(), [] (auto &a1, auto &b1) {
        if (a1.fi.fi != b1.fi.fi) {
            return a1.fi.fi > b1.fi.fi;
        }else {
            return a1.fi.se < b1.fi.se;
        }
    });

    ll t = v[0].se;
    cout << s[t] << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}