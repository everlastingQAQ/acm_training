#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a[n][n] = {};
	
	int x = 0;
	int y = (n - 1) / 2;
	a[x][y] = 1;
	
	for (int i = 2; i <= n * n; i++) {
		if (x - 1 >= 0 && y + 1 < n) {
			if (a[x - 1][y + 1] == 0) {
				a[--x][++y] = i;
			}else {
				a[++x][y] = i;
			}
		}else if (x - 1 < 0 && y + 1 < n) {
			x = n - 1;
			a[x][++y] = i;
		}else if (x - 1 >= 0 && y + 1 >= n) {
			y = 0;
			a[--x][y] = i;
		}else if (x - 1 < 0 && y + 1 >= n) {
			a[++x][y] = i;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
