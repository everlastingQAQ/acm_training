#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int x, y; cin >> x >> y;

    int a = 0, b = 0;
    for (int i = 30; i >= 0; i--) {
        if (((y >> i) & 1) == 0) {
            if (a + (1LL << i) <= x) {
                a += (1LL << i);
            }
        }
    }
    for (int i = 0; i <= 30; i++) {
        if ((y >> i) & 1) continue;
        b += (1LL << i);
    }
    for (int i = 30; i >= 0; i--) {
        if (((y >> i) & 1) == 0) {
            if (b - (1LL << i) >= x) {
                b -= (1LL << i);
            }
        }
    }
    int t1;
    if (x - a < b - x) {
        t1 = a;
    }else t1 = b;

    a = 0, b = 0;
    for (int i = 30; i >= 0; i--) {
        if (((x >> i) & 1) == 0) {
            if (a + (1LL << i) <= y) {
                a += (1LL << i);
            }
        }
    }
    for (int i = 0; i <= 30; i++) {
        if ((x >> i) & 1) continue;
        b += (1LL << i);
    }   
    for (int i = 30; i >= 0; i--) {
        if (((x >> i) & 1) == 0) {
            if (b - (1LL << i) >= y) {
                b -= (1LL << i);
            }
        }
    }
    int t2;
    if (y - a < b - y) {
        t2 = a;
    }else t2 = b;

    if (abs(t1 - x) < abs(t2 - y)) {
        cout << t1 << ' ' << y << '\n';
    }else {
        cout << x << ' ' << t2 << '\n';
    }
}   
    
int32_t main ()
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