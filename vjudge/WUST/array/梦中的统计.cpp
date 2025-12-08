#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int m, n;
	cin >> m >> n;
	
	int a[10] = {};
	for (int i = m; i <= n; i++) {
		string p = to_string(i);
		for (auto o : p) {
			a[o - '0']++;
		}
	}
	
	for (int i = 0; i <= 9; i++) {
		cout << a[i] << ' ';
	}
	
	return 0;
}
