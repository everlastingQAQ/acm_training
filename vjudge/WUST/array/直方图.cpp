#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a[100010] = {};
	int n;
	cin >> n;
	
	int m;
	cin >> m;
	a[m]++;
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		a[t]++;
		if (t > m) {
			m = t;
		}
	}
	
	for (int i = 0; i <= m; i++) {
		cout << a[i] << endl;
	}
	
	return 0;
}
