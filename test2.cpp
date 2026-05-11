#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;

// using i64 = long long;

const int mod = 998244353;

i64 qpow (i64 a, i64 b)
{
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inv (int x) {
    return qpow (x, mod - 2);
}

void solve ()
{
    cout << 7 * inv (3) % mod << '\n';
}

signed main ()
{
    // ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}