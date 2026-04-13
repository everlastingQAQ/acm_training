#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

void solve ()
{
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double d1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double d2 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double d3 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));

    if (d1 + d2 > d3 && d1 + d3 > d2 && d2 + d3 > d1) {
        cout << "triangle" << '\n';
    }else {
        cout << "collinear" << '\n';
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