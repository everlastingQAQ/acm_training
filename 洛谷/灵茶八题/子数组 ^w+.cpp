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
	vector <ll> v(n + 1);
    vector <ll> s(n + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		s[i] = s[i - 1] ^ v[i];
	}

	ll ans = 0;
    for (int i = 0; i < 23; i++) {
        ll cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += (s[j] >> i) & 1;
        }
        ans += cnt * (n - cnt + 1) * (1 << i);
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
