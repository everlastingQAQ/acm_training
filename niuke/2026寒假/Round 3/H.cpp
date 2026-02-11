#include <bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;

const ld eps = 1e-9;

struct point {
    long double x, y;
};

void solve ()
{
    point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    if (a.y == b.y) {
        ld t = fabsl(b.x - a.x) * fabsl(a.y);
        if (fabsl(t - 4.0) <= eps) {
            cout << 0 << '\n';
        }else {
            cout << "no answer\n"; 
        }
        return;
    }

    int t = a.x * b.y - b.x * a.y;
    ld tt = (4.0 - t) / (a.y - b.y);

    cout << fixed << setprecision(16) << tt << '\n';

}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 

/*
  /\_/\
 (= ._.)
 / >  \>
*/