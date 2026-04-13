#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int LIM = 1e6 + 10;
static int a[LIM];
int mx = 12;

void solve ()
{
	i64 n;
	cin >> n;
	if (!(n & 1)) {
		cout << "NO\n";
		return;
	}else if (n == 9) {
		cout << "YES\n";
		return;
	}else if (n % 5 == 0) {
		cout << "NO\n";
		return;
	}
	
	vector <int> v(13);
	int idx = 0;
	i64 x = n;
	while (x > 0) {
		x /= 10;
		idx++;
	}
	x = n;
	for (int i = 1; i <= idx; i++) {
		v[i] = x % 10;
		x -= v[i];
		x /= 10;
	}
	
	x = n % 10;
	int tt = idx;
	idx = 1;
	
	vector <int> p(10);
	if (n % 10 == 3) {
		p = {0, 7, 4, 1, 8, 5, 2, 9, 6, 3};
	}else if (n % 10 == 7) {
		p = {0, 3, 6, 9, 2, 5, 8, 1, 4, 7};
	}else if (n % 10 == 9) {
		p = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	}else if (n % 10 == 1) {
		p = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	}
//	cout << a[1] << '\n';
	while (idx < 1e6 + 10) {
		mx = max(mx, idx);
		if (idx == 1) {
			if (x == 9) {
				//a = v; /*
				//竟然没卡我 应该写成：
				for (int i = 1; i <= tt; i++) {
					a[i] = v[i];
				}
				//*/
				idx++;
				continue;
			}
			i64 ress = 0;
			bool ok1 = false;
			for (int i = 1; i <= 9; i++) {
				if ((x * i) % 10 == 9) {
					ok1 = true;
					ress = n * i;
					break;
				}
			}
			
			if (!ok1) {
				cout << "NO\n";
				return;
			}
			
			int iii = idx;
			while (ress > 0) {
				a[iii] += ress % 10;
				ress /= 10;
				iii++;
			}
			idx++;
			continue;
		}
		
		if (a[idx] == 9) {
			idx++;
			continue;
		}
		
		if (a[idx] == 0 && a[idx - 1] == 9 && a[idx + 1] == 0) {
			cout << "YES\n";
			return;
		}else if (a[idx] == 0 && a[idx + 1] == 0 && a[idx - 1]) {
			cout << "NO\n";
			return;
		}
		int t = 9 - a[idx] % 10;
		i64 res = n * p[t];

		int ii = idx;
		int c = 0;
		while (res > 0 || c > 0) {
			a[ii] += res % 10 + c;
			c = a[ii] / 10;
			a[ii] %= 10;
			res /= 10;
			ii++;
		}
		idx++;
	}
	cout << "NO\n";
	
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
		for (int i = 1; i <= mx + 1; i++) {
			a[i] = 0;
		}
	}
	return 0;
}
