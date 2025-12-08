#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;
	
void solve ()
{
	ll n, x;
	cin >> n >> x;
	vector <ll> v(n + 1, 0);
	vector <ll> d(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		d[i] = v[i] - v[i - 1];
	}
	
	for (int i = x + 1; i <= n; i++) {
		if (d[i - x] < 0) {
			d[i] += d[i - x];
		}
	}
	
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		if (d[i] < 0) {
			ans += abs(d[i]);
		}
	}
	
	cout << ans << '\n';
	
}

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}
