#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5;
const int mod = 998244353;

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

int inv (int x)
{
    return qpow(x, mod - 2);
}

void solve ()
{
    int n; cin >> n;
    vector <int> v(8);
    bool found = false;
    for (int i = 1; i <= 7; i++) {
        int t; cin >> t;
        if (t != 0) found = true;
        v[i] = t * inv(100) % mod;
    }

    if (!found) {
        cout << 0 << '\n';
        return;
    }

    vector <int> a(10);
    a[0] = v[1] * (v[2]) % mod * (v[3]) % mod * (1 - v[4] + mod) % mod * (v[5]) % mod * (v[6]) % mod * (v[7]) % mod;
    a[1] = (1 - v[1] + mod) * (1 - v[2] + mod) % mod * (v[3]) % mod * (1 - v[4] + mod) % mod * (1 - v[5] + mod) % mod * (v[6]) % mod * (1 - v[7] + mod) % mod;
    a[2] = (v[1]) * (1 - v[2] + mod) % mod * (v[3]) % mod * (v[4]) % mod * (v[5]) % mod * (1 - v[6] + mod) % mod * (v[7]) % mod;
    a[3] = (v[1]) * (1 - v[2] + mod) % mod * (v[3]) % mod * (v[4]) % mod * (1 - v[5] + mod) % mod * (v[6]) % mod * (v[7]) % mod;
    a[4] = (1 - v[1] + mod) * (v[2]) % mod * (v[3]) % mod * (v[4]) % mod * (1 - v[5] + mod) % mod * (v[6]) % mod * (1 - v[7] + mod) % mod;
    a[5] = (v[1]) * (v[2]) % mod * (1 - v[3] + mod) % mod * (v[4]) % mod * (1 - v[5] + mod) % mod * (v[6]) % mod * (v[7]) % mod;
    a[6] = (v[1]) * (v[2]) % mod * (1 - v[3] + mod) % mod * (v[4]) % mod * (v[5]) % mod * (v[6]) % mod * (v[7]) % mod;
    a[7] = (v[1]) * (1 - v[2] + mod) % mod * (v[3]) % mod * (1 - v[4] + mod) % mod * (1 - v[5] + mod) % mod * (v[6]) % mod * (1 - v[7] + mod) % mod;
    a[8] = (v[1]) * (v[2]) % mod * (v[3]) % mod * (v[4]) % mod * (v[5]) % mod * (v[6]) % mod * (v[7]) % mod;
    a[9] = (v[1]) * (v[2]) % mod * (v[3]) % mod * (v[4]) % mod * (1 - v[5] + mod) % mod * (v[6]) % mod * (v[7]) % mod;

    int ans = 0;

    auto cal = [&] (int x) -> int {
        string s = to_string(x);
        int cnt = 0;
        vector <int> count(10, 0);
        for (char c : s) {
            count[c - '0']++;
            cnt++;
        }
        count[0] += max(0LL, 4 - cnt);
        int res = 1;
        for (int i = 0; i <= 9; i++) {
            if (count[i] != 0) {
                res = res * qpow(a[i], count[i]) % mod; 
            }
        }
        return res;
    };

    // for (int i = 1; i <= 7; i++) {
    //     cout << v[i] << ' ' << a[i] << '\n';
    // }

    for (int i = 0; i <= n; i++) {
        int p = i, q = n - i;
        int cur = cal(p) * cal(q) % mod;
        ans = (ans + cur) % mod;
    }

    cout << ans << '\n';
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
} 

/*
  /\_/\
 (= ._.)
 / >  \>
*/
