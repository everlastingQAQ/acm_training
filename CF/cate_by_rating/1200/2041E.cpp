#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b;
    cin >> a >> b;
    cout << 3 << '\n';
    int sum = 3 * a - b;
    int x = -1e5;
    int y = sum - x;
    cout << x << ' ' << b << ' ' << y << '\n';
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