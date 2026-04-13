#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;

i64 qpow (i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    i64 x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    
    i64 ans = 0;
    i64 res = 1;
    i64 p0 = a * qpow(a + b, mod - 2) % mod;
    i64 p1 = b * qpow(a + b, mod - 2) % mod;

    auto cal1 = [&] (i64 &x, i64 &y) {
        i64 cnt = x / y - (x % y == 0 ? 1 : 0);
        i64 sum = res * (1 + (mod - qpow(p1, cnt)) % mod) % mod;
        sum = sum * qpow((1 + mod - p1) % mod, mod - 2) % mod;
        ans = (ans + (sum * p0) % mod) % mod;
        res = res * qpow(p1, cnt) % mod;
        x -= cnt * y;
    };

    auto cal2 = [&] (i64 &x, i64 &y) {
        i64 cnt = y / x - (y % x == 0 ? 1 : 0);
        res = res * qpow(p0, cnt) % mod;
        y -= cnt * x;
    };

    while (x >= 0 && y >= 0) {
        if (x > y) {
            cal1(x, y);
        }else if (x < y) {
            cal2(x, y);
        }else {
            ans = (ans + (res * p0 % mod)) % mod;
            break;
        }
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