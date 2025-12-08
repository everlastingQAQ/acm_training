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
 
ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin() + 1, v.end());

    ll l = 1, r = n;

    auto check = [&] (ll x) -> bool {
        //cout << x << '\n';
        if (n - x + 1 < 0 || v[n - x + 1] == 0) return false;
        ll t = sum - x;
        //cout << n - x << ' ' << v[n - x + 1] << ' ' << x << '\n';
        return t >= n - 1;
    };

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        //cout << mid << '\n';
        if (check(mid)) {
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
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}