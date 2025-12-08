#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a[n][n] = {};
	int num = 1;
	
	int i = 0;
	int j = 0;
	int lap = 0;
	do {
		for (int k = i; k < n - lap; k++) {
			a[i][k] = num;
			num++;
			if (num > n * n) goto f;
			j = k;
		}
		
		for (int k = 1 + lap; k < n - lap; k++) {
			a[k][j] = num;
			num++;
			if (num > n * n) goto f;
			i = k;
		}
		
		for (int k = j - 1; k >= lap; k--) {
			a[i][k] = num;
			num++;
			if (num > n * n) goto f;
			j = k;
		}
		
		for (int k = i - 1; k > lap; k--) {
			a[k][j] = num;
			num++;
			if (num > n * n) goto f;
			i = k;
		}
		
		lap++;
	}while (num <= n * n);
	
	f:
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
