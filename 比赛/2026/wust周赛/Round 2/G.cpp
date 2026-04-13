#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 5e5 + 10;
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
	vector <int> c(27);
    int n = 0;
    i64 t = 1;
    for (int i = 1; i <= 26; i++) {
        cin >> c[i];
        n += c[i];
        t = t * f[c[i]] % mod;
    }
    i64 res = f[n / 2] * f[n - n / 2] % mod * qpow(t, mod - 2) % mod;
    vector <vector <int> > dp(27, vector <int> (n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= n / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            if (c[i] > 0 && j >= c[i]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - c[i]]) % mod;
            }
        }
    }

    res = res * dp[26][n / 2] % mod;
    cout << res << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
} 
