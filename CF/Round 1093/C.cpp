#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 p, q;
    cin >> p >> q;
    i64 sum = p + 2 * q;
    i64 t = sqrtl(sum) + 2;
    for (i64 i = 1; i <= t; i++) {
        i64 pp = sum - i;
        if (pp % (i * 2 + 1) != 0) continue;
        i64 x = i;
        i64 y = (sum - x) / (x * 2 + 1);
        if (p >= abs(x - y)) {
            cout << x << ' ' << y << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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