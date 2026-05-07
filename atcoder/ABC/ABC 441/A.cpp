#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int a, b, x, y; cin >> a >> b >> x >> y;
    if (x <= a + 100 - 1 && x >= a && y <= b + 100 - 1 && y >= b) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
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