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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x3, y3, x4, y4;
    if (x1 == x2) {
        x3 = x1 + 1;
        x4 = x1 + 1;
        y3 = y2;
        y4 = y1;
    }else if (y1 == y2) {
        y3 = y1 + 1;
        y4 = y1 + 1;
        x3 = x1;
        x4 = x2;
    }else {
        x3 = x1;
        y3 = y2;
        x4 = x2;
        y4 = y1;
    }

    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4;
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