#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int qpow (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * i) % mod;
    }
    int x = qpow(2, n - 1);
    ans = (ans - x + mod) % mod;
    cout << ans << '\n';
}   

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   