#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 998244353;

ll n;

void solve ()
{
   	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll t;
		cin >> t;
		ll x = i * (n - i + 1);
		if (x & 1) ans ^= t;
	}
	cout << ans << '\n';
}

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	//cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}
