#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

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

void solve ()
{
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }else if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    int ans = (n * qpow(10, n - 1)) % mod;
    cout << ans;
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