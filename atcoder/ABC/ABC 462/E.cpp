#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    x = llabs(x);
    y = llabs(y);

    if (a < b) {
        int ans = 2 * a * min(x, y);
        if (x < y) {
            int t = (y - x) / 2;
            int cost = min(4 * a, a + b);
            ans += t * cost;
            if ((y - x) & 1) ans += min(3 * a, b);
        }else if (x > y) {
            int t = (x - y) / 2;
            int cost = min(4 * a, a + b);
            ans += t * cost;
            if ((x - y) & 1) ans += a;
        }
        cout << ans << '\n';
    }else if (a > b) {
        int ans = 2 * b * min(x, y);
        if (x < y) {
            int t = (y - x) / 2;
            int cost = min(4 * b, a + b);
            ans += t * cost;
            if ((y - x) & 1) ans += b;
        }else if (x > y) {
            int t = (x - y) / 2;
            int cost = min(4 * b, a + b);
            ans += t * cost;
            if ((x - y) & 1) ans += min(3 * b, a);
        }   
        cout << ans << '\n';
    }else {
        cout << a * (x + y) << '\n';
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