#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b;
    cin >> a >> b;
    int t = gcd(a, b);

    if (a == b) {
        cout << 0 << '\n';
        return;
    }

    auto cal = [&] (int x) -> int {
        for (int i = 2; i <= x / i; i++) {
            if (x % i == 0) return i;
        }
        return -1;
    };

    if (t != 1) {
        int x = lcm(a, b);
        cout << min(a + b, x) << '\n';
    }else {
        int x = cal(a);
        int y = cal(b);
        int ans = min(lcm(a, b), lcm(a, 2) + lcm(b, 2));

        if (x == -1 && y != -1) {
            ans = min({ans, b + a * y, b + y * 2 + 2 * a});
        }else if (x != -1 && y == -1) {
            ans = min({ans, a + b * x, a + x * 2 + 2 * b});
        }else if (x != -1 && y != -1) {
            ans = min({ans, a + b * x, a + x * 2 + 2 * b, b + a * y, b + y * 2 + 2 * a});
            ans = min({ans, a + 2 * x + 2 * y + b, x * y + a + b});
        }
 
        cout << ans << '\n';
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