#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll a, b, c;

void solve ()
{
    cin >> a >> b >> c;
    ld t = 1.0 * (a - b * c) / (c - 1);
    if (t - (ll)t == 0 && t >= 0) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
    }
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