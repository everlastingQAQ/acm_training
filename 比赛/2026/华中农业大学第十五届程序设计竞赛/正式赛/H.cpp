#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, m;

void solve ()
{
	string a = "fire";
	string b = "water";
	string c = "wind";
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	
	ll cnta = 0;
	ll cntb = 0;
	ll cntc = 0;
	for (int i = 0; i <= n - 4; i++) {
		if (s[i] == 'f' && s[i + 1] == 'i' && s[i + 2] == 'r' && s[i + 3] == 'e') {
			cnta++;
		}
		if (s[i] == 'w' && s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == 'd') {
			cntc++;
		}
	}
	for (int i = 0; i <= n - 5; i++) {
		if (s[i] == 'w' && s[i + 1] == 'a' && s[i + 2] == 't' && s[i + 3] == 'e' && s[i + 4] == 'r') {
			cntb++;
		}
	}
	
	ll cntaa = 0;
	ll cntbb = 0;
	ll cntcc = 0;
	
	for (int i = 0; i <= m - 4; i++) {
		if (t[i] == 'f' && t[i + 1] == 'i' && t[i + 2] == 'r' && t[i + 3] == 'e') {
			cntaa++;
		}
		if (t[i] == 'w' && t[i + 1] == 'i' && t[i + 2] == 'n' && t[i + 3] == 'd') {
			cntcc++;
		}
	}
	for (int i = 0; i <= m - 5; i++) {
		if (t[i] == 'w' && t[i + 1] == 'a' && t[i + 2] == 't' && t[i + 3] == 'e' && t[i + 4] == 'r') {
			cntbb++;
		}
	}
	
	if (cnta + cntb * cntc > cntaa + cntbb * cntcc) {
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
