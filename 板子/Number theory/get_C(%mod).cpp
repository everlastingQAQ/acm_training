#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e6;
const int mod = 998244353;

i64 f[N], g[N];

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

i64 C (i64 n, i64 m)
{
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void init ()
{
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    g[N - 1] = qpow(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        g[i] = g[i + 1] * (i + 1) % mod;
    }
}

void solve ()
{
    
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}   