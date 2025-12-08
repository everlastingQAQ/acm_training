#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main ()
{
	ll n;
	cin >> n;
	
	vector<string> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (j == i) continue;
			int mod = 0;
			for (char c : a[i]) {
				mod = (mod * 10 + (c - '0')) % 11;
			}
			for (char c : a[j]) {
				mod = (mod * 10 + (c - '0')) % 11;
			}
			if (mod == 0) cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
