#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;
using pii = pair<pi, ll>;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    vector <pii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi.fi >> v[i].fi.se >> v[i].se;
        if (v[i].se == 1) {
            v[i].fi.se++;
        }
    }

    sort(v.begin(), v.end(), [] (auto &a1, auto &b1) {
        if (a1.fi.se != b1.fi.se) {
            return a1.fi.se < b1.fi.se;
        }else {
            if (a1.se != b1.se) {
                if (a1.se == 2) {
                    return a1 < b1;
                }else if (b1.se == 2) {
                    return b1 < a1;
                }
            }
        }
    });

    ll dm = 0;
    ll t = 0;
    ll j = 0;
    for (int i = 1; i <= n; i++) {
        if (v[j].fi.se > i + t) {
            break;
        }else {
            while (v[j].fi.se <= i + t) {
                if (v[j].se != )
            }

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