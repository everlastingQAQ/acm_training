#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1001005;
const int mod = 1000000007;

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
    vector <int> v(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int ans = 1;
    v[n + 1] = 1;
    int t = 1000;
    int cnt = 0;
    
    for (int i = 1; i <= n + 1; i++) {
        if (v[i] == 0) {
            cnt++;
            continue;
        }
        if (cnt != 0) {
            ans = ans * C(t - v[i] + cnt, cnt) % mod;
            cnt = 0;
        }
        t = v[i];
    }

    cout << ans << '\n';
}       
    
signed main ()
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