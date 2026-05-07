#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n, m; cin >> n >> m;
    vector <ll> v(n);
    ll sum = 0;
    for (ll &x : v) {
        cin >> x;
        sum += x;
    }
    if (sum <= m) {
        cout << "infinite" << '\n';
        return;
    }

    ll l = 0, r = 1e15;

    auto check = [&] (ll x) -> bool {
        ll summ = 0;
        for (int i = 0; i < n; i++) {
            summ += min(x, v[i]);
        }
        return summ <= m;
    };

    while (l <= r) {
        ll mid = l + (r - l) / 2;
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
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}