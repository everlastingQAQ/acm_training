#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
	cin >> n;
	vector <int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	if (n == 2) {
		if (v[1] == 2) {
			cout << "NO\n";
			return;
		}
	}
	if (n == 3) {
		if (v[2] != 2) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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
