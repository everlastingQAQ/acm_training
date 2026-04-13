#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, m;

void solve ()
{
    cin >> n >> m;
    vector <ll> v(n);
    ll s = 0;
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s += v[i];
        mx = max(mx, v[i]);
    }

    ll l = mx, r = s;

    auto check = [&] (ll md) -> bool {
        ll sum = 0;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i];
            if (sum > md) {
                cnt++;
                sum = v[i];
            }
        }
        return cnt + 1 <= m;
    }; 

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
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