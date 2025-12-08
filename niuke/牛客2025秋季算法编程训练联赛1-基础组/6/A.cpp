#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define fi first
#define se second

#define ll long long

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll a, b, c;

void solve ()
{
    long long a;
    cin >> a >> b >> c;
    if (a + b <= c || a + c <= b || c + b <= a) {
        cout << "wtnl" << '\n';
        return;
    }
    
    ld sum = 0;
    ld x = 1.0 * (a + b - c) / 2;
    ld y = 1.0 * (a + c - b) / 2;
    ld z = 1.0 * (b + c - a) / 2;
    sum = x + y + z;

    ld mn = min({x, y, z});
    ld mx = max({x, y, z});
    ld md = sum - mn - mx;

    cout << "Yes" << '\n';
    cout << fixed << setprecision(2) << mn << ' ' << md << ' ' << mx << '\n';
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