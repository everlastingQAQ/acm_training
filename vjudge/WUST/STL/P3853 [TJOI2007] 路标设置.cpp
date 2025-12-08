#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll l, n, k;

bool check (ll x, const vector <ll> &v) 
{
    ll sum = 0;

    for (ll i = 0; i < n - 1; i++) {
        if (v[i + 1] - v[i] > x) {
            ll t = (v[i + 1] - v[i] - 1) / x;
            sum += t;
        }
    }

    if (l - v[n - 1] > x) {
        sum += (l - v[n - 1] - 1) / x;
    } 

    if (sum > k) {
        return false;
    }else {
        return true;
    }
}

void solve ()
{
    cin >> l >> n >> k;

    vector <ll> v(n);

    for (ll &i : v) {
        cin >> i;
    }

    ll left = 1, r = l;
    ll ans = l;

    while (left < r) {
        ll mid = left + (r - left) / 2;
        if (check(mid, v)) {
            ans = mid;
            r = mid;
        }else {
            left = mid + 1;
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