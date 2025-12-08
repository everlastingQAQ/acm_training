#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int m, n;
	cin >> m >> n;
	
	int a[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			if (t == a[i][j]) cnt++;
		}
	}
	
	double p = 100.0 * cnt / n / m;
	
	cout << fixed << setprecision(2) << p;
	
	return 0;
}
