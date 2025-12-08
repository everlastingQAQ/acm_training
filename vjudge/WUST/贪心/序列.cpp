#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;

    vector <pair<pair<ll, ll>, ll> > v(n);
    ll mx = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi.fi >> v[i].fi.se >> v[i].se;
        mx = max(mx, v[i].fi.se);
    }

    sort(v.begin(), v.end(), [] (const pair<pair<ll, ll>, ll> &a1, pair<pair<ll, ll>, ll> &b1) {
        if (a1.fi.se != b1.fi.se) {
            return a1.fi.se < b1.fi.se;
        }else {
            return a1.fi.fi < b1.fi.fi;
        }
    }); 

    vector <bool> a(mx + 1, false);
    for (int i = 0; i < n; i++) {
        ll t = v[i].se;
        for (int j = v[i].fi.se; j >= v[i].fi.fi; j--) {
            if (a[j] == true) {
                t--;
            }
            if (t == 0) {
                break;
            }
        }
        for (int j = v[i].fi.se; j >= v[i].fi.fi && t != 0; j--) {
            if (a[j] == false) {
                a[j] = true;
                t--;
            }
            if (t == 0) {
                break;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= mx; i++) {
        if (a[i] == true) {
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