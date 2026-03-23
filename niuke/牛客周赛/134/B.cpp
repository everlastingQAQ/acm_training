#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    while (c >= x || b >= y) {
        b += c / x;
        c %= x;
        int t = b / y;
        b %= y;
        c += t;
        a += t;
    }
    cout << a << '\n';
}   
    
int main ()
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