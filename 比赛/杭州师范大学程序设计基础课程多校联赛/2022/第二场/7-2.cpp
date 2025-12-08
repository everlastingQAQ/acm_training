#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ld t1 = 1.0L * a / b;
    ld t2 = 1.0L * c / d;

    if (t1 == t2) {
        cout << 1 << '\n';
    }else if (t1 > t2) {
        cout << a << ' ' << b << '\n';
    }else if (t1 < t2) {
        cout << c << ' ' << d << '\n';
    }

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