#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n;

void solve ()
{
	cin >> n;
	vector <ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	for (int i = 0; i < n; i++) {
		string s = to_string(v[i]);
		for (int k = 0; k < (ll)s.size(); k++) {
			ll t = s[k] - '0';
			ll pos = k;
			for (ll j = k + 1; j < (ll)s.size(); j++) {
				ll a = s[j] - '0';
//				cout << j << ' ' << s[j] << '\n';
				if (a >= t) {
					t = a;
					pos = j;				
				}
			}
			if (pos != k && s[pos] > s[k]) {
//				cout << s[pos] << ' ' << s[k] << '\n';
				swap(s[pos], s[k]);
				break;
			}
		}
		
		v[i] = stoll(s);
	}
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += v[i];
//		cout << v[i] << ' ';
	}
//	cout << '\n';
	
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
