#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if ((xa > xb && xa < xc) || (xa > xc && xa < xb)) {
        cout << 1 << '\n';
        return;
    }else if ((xb > xa && xb < xc) || (xb > xc && xb < xa)) {
        cout << 2 << '\n';
        return;
    }else if ((xc > xa && xc < xb) || (xc > xb && xc < xa)) {
        cout << 3 << '\n';
        return;
    }

    if (xa == xb) {
        if ((ya > yb && ya < yc) || (ya > yc && ya < yb)) {
            cout << 1 << '\n';
            return;
        }else if ((yb > ya && yb < yc) || (yb > yc && yb < ya)) {
            cout << 2 << '\n';
            return;
        }else if ((yc > ya && yc < yb) || (yc > yb && yc < ya)) {
            cout << 3 << '\n';
            return;
        }
    }
}   
    
signed main ()
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