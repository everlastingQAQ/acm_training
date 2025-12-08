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
 
ll n, a, b;

void solve ()
{
    cin >> n >> a >> b;
    vector <ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll l = *min_element(v.begin(), v.end()) / (a + b);
    ll r = *max_element(v.begin(), v.end()) / a + 1;

    auto check = [&] (ll m) -> bool {
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] <= m * a) continue;
            else {
                cnt += ceil(1.0 * (v[i] - m * a) / b);
            }
        }
        return cnt <= m;
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