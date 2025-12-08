#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll k, n;

void solve ()
{
	cin >> k >> n;
	vector <ll> v(n);
//	vector <ll> s(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
//		s[i] = s[i - 1] + v[i];
	}
	
	ll sum = 0;
	ll j = 0;
	ll t = 0;
	
	for (int i = 0; i < k; i++) {
		
//		cout << sum << ' ' << v[j + 1] << '\n';
		if (sum >= v[j + 1] && j < n - 1) {
			j++;
		}
//				cout << v[j] << ' ' << sum << '\n';
		sum += v[j];
		if (j == n - 1) {
			t = k - i - 1;
			break;
		}
//		cout << j << '\n';
	}
	
	sum += max(0LL, t) * v[n - 1];
	
	cout << sum << '\n';
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
