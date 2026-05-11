#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, h;

bool check (ll x, const vector <ll> &v) 
{
    ll sum = 0;
    
    for (int i = 0; i < n - 1; i++) {
        sum += min(x, v[i + 1] - v[i]);
    }

    sum += x;

    if (sum >= h) {
        return true;
    }else {
        return false;
    }

}

void solve ()
{
    cin >> n >> h;

    vector <ll> v(n);

    for (ll &i : v) {
        cin >> i;
    }

    ll l = 0, r = h;
    ll ans = h;

    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid, v)) {
            ans = mid;
            r = mid;
        }else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
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