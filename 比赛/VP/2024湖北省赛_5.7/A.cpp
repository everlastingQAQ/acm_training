#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int x, y;
    cin >> x >> y;
    int ans = lcm(x, y) / gcd(x, y);
    cout << 1 << ' ' << ans << '\n';
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