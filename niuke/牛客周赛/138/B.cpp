#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 x, y;
    cin >> x >> y;
    if (x < y) swap(x, y);
    i64 ans = x;
    i64 yy = y;
    while (yy > 0) {
        ans = max(ans, (x ^ yy));
        yy /= 2;
    }
    while (x > 0) {
        ans = max(ans, (x ^ y));
        x /= 2;
    }
    cout << ans << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 