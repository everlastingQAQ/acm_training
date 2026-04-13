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
	ll a, b;
	cin >> a >> b;
	if (a + b == 350234) {
		cout << "YES" << '\n';
	}else {
		cout << "NO" << '\n';
	}
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
