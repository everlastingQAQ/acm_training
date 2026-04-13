#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	i64 n, a, b;
	cin >> n >> a >> b;
	if (2 * a <= b) {
		i64 ans = n * a;
		cout << ans << '\n';
	}else {
		i64 t = n / 2 * b;
		if (n & 1) {
			t += a;
		}
		cout << t << '\n';
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
