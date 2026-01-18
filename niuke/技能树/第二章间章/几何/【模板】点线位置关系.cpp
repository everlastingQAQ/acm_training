#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int t1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (t1 > 0) {
        cout << 1 << '\n';
    }else if (t1 < 0) {
        cout << 2 << '\n';
    }else {
        if (x3 >= min(x1, x2) && x3 <= max(x1, x2) && y3 >= min(y1, y2) && y3 <= max(y1, y2)) {
            cout << 3 << '\n';
        }else {
            cout << 4 << '\n';
        }
    }
}   
    
signed main ()
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