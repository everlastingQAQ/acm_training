#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, m;
	cin >> n >> m;
	
	double a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	double b[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				b[i][j] = a[i][j];
			}else {
				b[i][j] = round((a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1]) / 5.0);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
