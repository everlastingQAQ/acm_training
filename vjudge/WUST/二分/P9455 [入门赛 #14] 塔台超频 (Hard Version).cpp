#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

bool check (ll x, const vector <pair<ll, ll> > &v)
{
    ll t = v[0].fi + v[0].se + x;

    for (int i = 1; i < n; i++) {
        if (t < v[i].fi) {
            return false;
        }else {
            t = max(t, v[i].fi + v[i].se + x);
        }
    }

    return true;
}

void solve ()
{
    cin >> n;

    vector <pair<ll, ll> > v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }

    ll l = 0, r = v[n - 1].fi;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid, v)) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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