#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    ll ans = 0;
    ll a = 1, b = 0;
    if (n == 0) {
        cout << 1 << '\n';
        return;
    }
    for (int i = 0; i <= n; i++) {
        ll t = b;
        b = a;
        if (i == 0) {
            a == 2;
        }else {
            a = a + t;
        }
        //cout << a << ' ' << b << '\n';
    }

    ans = a + b;

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
