#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b;
    while (cin >> a >> b) {
        int C = b * gcd(a, b);
        int A = 1;
        int B = -a;
        int t = B * B - 4 * A * C;
        int tt = sqrtl(t);
        if (t < 0 || tt * tt != t) {
            cout << "No Solution\n";
            continue;
        }
        int x = sqrtl(t) - B;
        if (x % (2 * A) != 0) {
            cout << "No Solution\n";
            continue;
        }
        int y = x / 2 / A;
        x = a - y;
        if (x > y) swap(x, y);
        cout << x << ' ' << y << '\n';
    }    
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