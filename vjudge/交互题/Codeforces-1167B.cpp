#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    vector <int> v(6);
    v[0] = 4, v[1] = 8, v[2] = 15, v[3] = 16, v[4] = 23, v[5] = 42;
    cout << '?' << ' ' << 1 << ' ' << 2 << endl;
    int t1;
    cin >> t1;
    cout << '?' << ' ' << 3  << ' ' << 4 << endl;
    int t2;
    cin >> t2;
	cout << '?' << ' ' << 1  << ' ' << 3 << endl;
	int t3;
	cin >> t3;
	cout << '?' << ' ' << 4  << ' ' << 5 << endl;
	int t4;
	cin >> t4;
	int t5 = 4 * 8 * 15 * 16 * 23 * 42 / t1 / t2;
	int sum = 4 + 8 + 15 + 16 + 23 + 42;

	int p = (t3 * t4 + t2 * t4 + t2 * t5);
	int q = (t1 + t3 + (t3 * t4) / t2) * t3 * t4;
	// cout << p << ' ' << q << '\n';
	// cout << sum << '\n';
	int temp1 = (sum * t3 * t4 + sqrt(sum * sum * t3 * t3 * t4 * t4 - 4 * p * q)) / 2 / p;
	int temp2 = (sum * t3 * t4 - sqrt(sum * sum * t3 * t3 * t4 * t4 - 4 * p * q)) / 2 / p;

	vector <int> ans;
	auto check = [&] (int a1) -> bool {
		vector <int> b(6);
		b[0] = a1;
 		b[1] = t1 / b[0];
		b[2] = t3 / b[0];
		b[3] = t2 / b[2];
		b[4] = t4 / b[3];
		b[5] = sum - b[0] - b[1] - b[2] - b[3] - b[4];
		ans = b;
		sort(b.begin(), b.end());
		if (b == v) {
			return true;
		}else {
			return false;
		}
	};

	if (check(temp1)) {
		cout << '!' << ' ';
		for (auto x : ans) {
			cout << x << ' ';
		}
		cout << endl;
	}else if (check(temp2)) {
		cout << '!' << ' ';
		for (auto x : ans) {
			cout << x << ' ';
		}
		cout << endl;
	}
} 

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 