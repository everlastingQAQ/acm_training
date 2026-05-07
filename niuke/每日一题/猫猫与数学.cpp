#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (a == b) {
        if (a == 1) {
            cout << 1 << '\n';
        }else {
            cout << 0 << '\n';
        }
        return;
    }

    if (gcd(a, b) != 1) {
        cout << 0 << '\n';
        return;
    }

    if (b - a == 1) {
        cout << -1 << '\n';
        return;
    }

    i64 d = b - a;
    i64 ans = 1e18;

    for (i64 i = 2; i * i <= d; i++) {
        if (d % i == 0) {
            ans = min(ans, (i - a % i) % i);
            while (d % i == 0) {
                d /= i;
            }
        }
    }

    if (d > 1) {
        ans = min(ans, (d - a % d) % d);
    }

    cout << ans << '\n';
}   

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}