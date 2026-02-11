#include <bits/stdc++.h>
using namespace std;
#define int long long

int exgcd (int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void solve ()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    int g = exgcd(a, b, x, y);

    if (c % g != 0) {
        cout << -1 << '\n';
        return;
    }

    x *= c / g;
    y *= c / g;
    
    int dx = b / g;
    int dy = a / g;

    if (x < 0) {
        int t = (dx - x) / dx;
        x += dx * t;
        y -= dy * t;
    }else {
        int t = (x - 1) / dx;
        x -= dx * t;
        y += dy * t;
    }

    if (y <= 0) {
        cout << x << ' ' << y + dy * ((dy - y) / dy) << '\n';
    }else {
        cout << (y - 1) / dy + 1 << ' ' << x << ' ';
        cout << (y - (y - 1) / dy * dy) << ' ' << (x + (y - 1) / dy * dx) << ' ' << y << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/