#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
	cin >> n;
	vector <i64> v(n + 1);
	vector <i64> a, b;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (v[i] & 1) {
			a.push_back(v[i]);
		}else {
			b.push_back(v[i]);
		}
	}  

	sort(a.begin(), a.end(), greater<>());
	sort(b.begin(), b.end(), greater<>());
	i64 ca = 0;
	if (!a.empty()) ca = a[0];
	i64 cb = 0;
	if (!b.empty()) cb = b[0];

	cout << max(ca, cb) << ' ';

	int pb = 0, pa = 0;
	for (int i = 1; i < n; i++) {
		// cout << pa << ' ' << a[pa] << ' ' << pb << ' ' << b[pb] << '\n';
		// cout << i << ": " << ca << ' ' << cb << '\n';
		if (pb < b.size()) ca += b[pb];
		if (pb >= b.size()) ca = 0;
		if (pa < a.size()) cb += a[pa];
		if (pa >= a.size()) cb = 0;
		pb++, pa++;
		// cout << i << ": " << ca << ' ' << cb << '\n';
		cout << max(ca, cb) << ' ';
	}
	cout << '\n';

} 

int main ()
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