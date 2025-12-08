#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1000000;
const double eps = 1e-10;
const ll mod = 998244353;
ll n, k;

bool check (ll x, const vector <pair<ll, ll> > &v)
{
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        sum += (v[i].fi / x) * (v[i].se / x);
        if (sum >= k) {
            return true;
        }
    }

    return sum >= k;
}

void solve ()
{
    cin >> n >> k;
    vector <pair<ll, ll> > v(n);

    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
        mx = max(v[i].fi * v[i].se, mx);
    }

    ll l = 1, r = mx;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid, v)) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }

    cout << r << '\n';
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