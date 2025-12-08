#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, m;
	cin >> n >> m;
	
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	int sum = 0;
	if (n == 1) {
		for (int j = 0; j < m; j++) {
			sum += a[0][j];
		}
	}else if (m == 1) {
		for (int i = 0; i < n; i++) {
			sum += a[i][0];
		}
	}else {
		for (int i = 0; i < m; i++) {
			sum += a[0][i] + a[n - 1][i];
		}
		for (int i = 1; i <= n - 2; i++) {
			sum += a[i][0] + a[i][m - 1];
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
