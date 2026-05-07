#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int x, y;
    cin >> x >> y;
    int mxx = x * 2500;
    if (mxx < y) {
        // cerr << "11";
        cout << -1 << '\n';
        return;
    }

    int nm = y % 500;
    if (nm != 0) {
        // cerr << "22";
        cout << -1 << '\n';
        return;
    }

    int cnt = y / 500;

    int mx = cnt / 5;

    // cerr << "cnt : " << cnt << '\n';
    // cerr << "max : " << mx << '\n';
    int res = cnt % 5;
    
    if (mx == 0 && res == 3) {
        cout << -1 << '\n';
        return;
    }
    
    int a = 0, b = 0, c = 0;
    if (res % 2 == 0) {
        c = mx;
        b = res / 2;
        a = x - b - c;
        // 
    } else {
        c = mx - 1;
        b = (res + 5) / 2;
        a = x - b - c;
    }

    cout << a << ' ' << b << ' ' << c << '\n';
} 

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 