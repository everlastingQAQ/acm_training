#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll m, n;

bool check (ll x, const vector <ll> &v)
{
    ll sump = 0;
    ll cnt = 0;

    for (int i = 0; i < n; i++) {
        if (sump + v[i] > x) {
            sump = 0;
            cnt++;
        }
        sump += v[i];
    }
    
    if (cnt + 1 > m) {
        return false;
    }else {
        return true;
    }
}

void solve ()
{
    cin >> n >> m;
    vector <ll> v(n);

    ll sum = 0;
    ll mx = 0;
    for (ll &i : v) {
        cin >> i;
        sum += i;
        mx = max(i, mx);
    }

    ll l = mx, r = sum;
    
    ll ans = sum;
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
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}