#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;
const int n = 2e6;
i64 dp[n + 1];

i64 qpow (i64 a, i64 b)//a的b次方
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
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % mod;
    }
}

void solve ()
{
    i64 x;
    cin >> x;
    i64 ans = dp[x] * qpow(qpow(x - 1, x), mod - 2) % mod;
    cout << ans << '\n';
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