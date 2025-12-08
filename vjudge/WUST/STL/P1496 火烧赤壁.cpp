#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

bool cmp (const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if (a.fi != b.fi) {
        return a.fi < b.fi;
    }
    return a.se < b.se;
}

void solve ()
{
    cin >> n;

    vector <pair<ll, ll> > v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }

    sort(v.begin(), v.end(), cmp);

    ll ans = 0;
    ll l = v[0].fi, r = v[0].se;
    ans += r - l;
    for (int i = 1; i < n; i++) {
        if (v[i].fi <= r) {
            if (v[i].se > r) {
                l = r;
                r = v[i].se;
                ans += r - l;
            }else {
                l = v[i].fi;
            }
        }else {
            l = v[i].fi;
            r = v[i].se;
            ans += r - l;
        }
    }

    cout << ans << endl;
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