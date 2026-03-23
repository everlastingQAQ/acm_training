#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n, k, p, m;
	cin >> n >> k >> p >> m;
	vector <int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int d = p - k;
	int cur = m;
	int x = v[p];
	if (d > 0) {
		vector <int> vv;
		for (int i = 1; i < p; i++) {
			vv.push_back(v[i]);
		}
		sort(vv.begin(), vv.end());
		for (int i = 0; i < d; i++) {
			cur -= vv[i];
		}
		if (cur < 0) {
			cout << 0 << '\n';
			return;
		}
	}
	cur -= x;
	if (cur < 0) {
		cout << 0 << '\n';
		return;
	}
	int ans = 1;
	v.erase(v.begin() + p);
	sort(v.begin() + 1, v.end());
	int diff = 0;
	for (int i = 1; i <= n - k; i++) {
		diff += v[i];
	}
	diff += x;
	int temp = cur / diff;
	ans += temp;
	cout << ans << '\n';
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