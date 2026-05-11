#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	i64 a, b, c, m;
	cin >> a >> b >> c >> m;

	auto cal = [&] (i64 a, i64 b, i64 c) -> i64 {
		i64 t1 = lcm(a, b);
		i64 t2 = lcm(a, c);
		i64 t3 = lcm(t1, c);
		i64 d1 = m / a;
		i64 d2 = m / t1 + m / t2 - m / t3;
		i64 d3 = m / t3;
		
		i64 res1 = d3 * 2 + (d2 - d3) * 3 + (d1 - d2) * 6;
		return res1;
	};
	
	i64 ans1 = cal(a, b, c);
	i64 ans2 = cal(b, a, c);
	i64 ans3 = cal(c, a, b);

	cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
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