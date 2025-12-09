#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 998244353;

ll n, k;
string s;

void solve ()
{
	cin >> n >> k >> s; s = ' ' + s;
	ll cnt = 0;
	vector <ll> v;
    for (int i = 1; i <= n; i++) {
		if (s[i] == '0') {
			cnt++;
		}else {
			cnt = 0;
		}
		// cout << cnt << ' ' << i << '\n';
		if (cnt == k) {
			v.push_back(i);
			cnt = 0;
		}
	}

	// for (auto x : v) {
	// 	cout << x << ' ';
	// }
	// cout << '\n';

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] - 1 << ' ';
	}
	for (int i = 0; i <= n - v.size(); i++) {
		cout << n << ' ';
	}
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
