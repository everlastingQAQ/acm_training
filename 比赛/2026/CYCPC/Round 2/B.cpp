#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

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

void solve ()
{
  	int n;
  	cin >> n;
  	i64 ans = 0;
  	for (int i = 1; i <= n; i++) {
  		i64 t;
  		cin >> t;
  		if (t <= 3) continue;
  		i64 cur = (((t * t % mod * t % mod) % mod - 7 * t % mod + mod) % mod - 6 + mod) % mod;
  		cur = cur * qpow(6LL, mod - 2) % mod;
  		ans ^= cur;
  	}  
  	cout << ans << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 