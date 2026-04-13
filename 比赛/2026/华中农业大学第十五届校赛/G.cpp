#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n, q;
	cin >> n >> q;
	vector <array <i64, 3> > v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i][0];
	}
	for (int i = 1; i <= n; i++) {
		cin >> v[i][1];
	}
	for (int i = 1; i <= n; i++) {
		cin >> v[i][2];
	}
	
	i64 res = 0;
	vector <array <i64, 3> > a;
	a.reserve(n + 1);
	for (int i = 1; i <= n; i++) {
		if (v[i][0] > v[i][1]) {
			res += v[i][2];
		}else {
			a.push_back({v[i][1], v[i][2]});
		}
	}
	
	sort(a.begin(), a.end(), [] (auto aa, auto bb) {
		if (aa[0] != bb[0]) {
			return aa[0] < bb[0];
		}else {
			return aa[1] > bb[1];
		}
	});
	
	i64 m = a.size();
	vector <i64> pre(m + 1);
	if (!a.empty()) pre[0] = a[0][1];
	for (int i = 1; i < m; i++) {
		pre[i] = max(pre[i - 1], a[i][1]);
	}
	
	while (q--) {
		i64 t;
		cin >> t;
		if (a.empty()) {
			cout << res << '\n';
			continue;
		}
		if (!a.empty() && t < a[0][0]) {
			cout << res << '\n';
			continue;
		}
		int l = 0, r = m - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[mid][0] <= t) {
				l = mid + 1;
			}else {
				r = mid - 1;
			}
		}
		cout << res + pre[r] << '\n';
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