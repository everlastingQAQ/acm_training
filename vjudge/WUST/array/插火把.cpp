#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, m, k;
	cin >> n >> m >> k;
	
	bool a[n][n] = {};
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x -= 1;
		y -= 1;
		a[x][y] = true;
		for (int j = x - 2; j <= x + 2; j++) {
			if (j >= n || j < 0) continue;
			a[j][y] = true;
		}
		for (int k = y - 2; k <= y + 2; k++) {
			if (k >= n || k < 0) continue;
			a[x][k] = true;
		}
		if (x - 1 >= 0 && y - 1 >= 0) a[x - 1][y - 1] = true;
		if (x + 1 < n && y - 1 >= 0) a[x + 1][y - 1] = true;
		if (x - 1 >= 0 && y + 1 < n) a[x - 1][y + 1] = true;
		if (x + 1 < n && y + 1 < n) a[x + 1][y + 1] = true;
	}
	
	for (int i = 0; i < k; i++) {
		int o, p;
		cin >> o >> p;
		o--;
		p--;
		a[o][p] = true;
		for (int i = o - 2; i <= o + 2 && i >= 0 && i < n; i++) {
			for (int j = o - 2; j <= o + 2 && j >= 0 && j < n; j++) {
				a[i][j] = true;
			}
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == false) {
				cnt++;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
	
}
