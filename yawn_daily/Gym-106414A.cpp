#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    int x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int ans = 0;
    if (x1 == x2) {

    }else if ((x1 - x2) & 1) ans++;
    else ans += 2;

    if (y1 == y2) {

    }else if ((y1 - y2) & 1) ans++;
    else ans += 2;
    cout << ans << '\n';
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