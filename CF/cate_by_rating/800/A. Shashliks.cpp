#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll k, a, b, x, y;

void solve ()
{
    cin >> k >> a >> b >> x >> y;

    if (x > y) {
        swap(x, y);
        swap(a, b);
    }

    ll ans = 0;
    if (k >= a) {
        ll cnt = (k - a) / x + 1;
        ans += cnt;
        k -= cnt * x;
    }

    if (k >= b) {
        ll cnt = (k - b) / y + 1;
        ans += cnt;
        k -= cnt * y;
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