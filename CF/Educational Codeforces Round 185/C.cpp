#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
 
ll n, k;

void solve ()
{
    cin >> n >> k;
    vector <ll> v(n);
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(v.begin(), v.end());
    sort(a.begin(), a.end());

    auto check = [&] (ll x, ll t) -> bool {
        return t * (a[x] + 1) + a[x] <= k;
    }; 

    ll cnt = 0;
    ll rem = a.size() - 1;
    ll l, r;
    for (int i = 0; i < n; i++) {
        ll t = v[i];
        l = 0, r = rem;
        if (v[i] * (a[0] + 1) + a[0] > k) break;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (check(mid, t)) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        if (r < 0) break;
        rem = r - 1;
        cnt++;
    }

    cout << cnt << '\n';
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