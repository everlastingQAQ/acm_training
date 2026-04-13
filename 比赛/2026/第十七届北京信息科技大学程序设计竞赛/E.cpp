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
    ll a = 4, b = 12;
    ll c = 0;

    if (n == 1) {
        cout << 4 << '\n';
        return;
    }else if (n == 2) {
        cout << 12 << '\n';
        return;
    }

    ll ans = 16; 
    for (int i = 3; i <= n; i++) {
        c = (3 * b - a + mod) % mod;
        a = b;
        b = c;
        ans = (ans + c) % mod;
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