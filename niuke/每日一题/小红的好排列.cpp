#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6;
const int mod = 1e9 + 7;

int f[N], g[N];

int qpow (int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int C (int n, int m)
{
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void init ()
{
    f[0] = 1, g[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }
}

void solve ()
{
    int n; cin >> n;
    if (n == 2) {
        cout << 0 << '\n';
        return;
    }

    int t = n / 3;
    int x = n / 2 - t;
    int y = t - x;
    int ans = C(t, x) * f[x] % mod * C(n - t, x) % mod * f[y] % mod * C(t, y) % mod * f[n - t] % mod;
    cout << ans << '\n';
    
}   
    
int32_t main ()
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