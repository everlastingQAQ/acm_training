#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	i64 n;
	cin >> n;
	if (n & 1) {
		i64 t1 = n / 2;
		i64 t2 = n - n / 2;
		i64 ans = t1 * t2;
		cout << ans << '\n';
	}else {
		i64 l = n / 2, r = n / 2;
		while (lcm(l, r) != l * r) {
			l--;
			r++;
		}
		i64 ans = lcm(l, r);
		cout << ans << '\n';
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;	
	while (_--) {
		solve();
	}
	return 0;
}
