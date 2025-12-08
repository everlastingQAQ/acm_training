#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m, x, y;

void solve ()
{
    cin >> n >> m >> x >> y;

    if (n == 1 && m == 1) {
        cout << 0 << '\n';
    }else if (n == 1 || m == 1) {
        cout << 1 << '\n';
    }

    ll mn = min(n, m);
    cout << mn + 1 << '\n';
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