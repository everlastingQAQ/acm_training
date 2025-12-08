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
 
ll x, y;

void solve ()
{
    cin >> x >> y;
    if (x > 0 && y > 0) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }else if (x > 0 && y < 0) {
        cout << x + 1 << ' ' << y - 1 << '\n';
    }else if (x < 0 && y > 0) {
        cout << x - 1 << ' ' << y + 1 << '\n';
    }else if (x < 0 && y < 0) {
        cout << x - 1 << ' ' << y - 1 << '\n';
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