#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;
const int N = 3e5;

i64 f[N], g[N];

i64 qpow (i64 a, i64 b)
{
    int res = 1;
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
    f[0] = 1, g[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }
}

void solve ()
{
  	int n;
  	cin >> n;
  	string s;
  	cin >> s;
  	int c1 = 0, c0 = 0;
  	for (int i = 0; i < n; i++) {
  		c0 += (s[i] == 'j');
  		c1 += (s[i] == 'o');
  	}  
  	int co = 0, ce = 0;
  	if (n & 1) {
  		co = n / 2 + 1;
  		ce = n - co;
  	}else {
  		co = n / 2;
  		ce = n / 2;
  	}

  	if (c0 > co || c1 > ce) {
  		cout << 0 << '\n';
  		return;
  	}

  	i64 ans = C(n - c0 - c1, ce - c1) * f[ce] % mod * f[co] % mod;
  	cout << ans % mod << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
} 