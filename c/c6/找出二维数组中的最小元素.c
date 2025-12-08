#include <stdio.h>

int main ()
{
	int m, n;
	scanf("%d %d", &m, &n);
	
	int a[m][n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("before:\n");
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	
	printf("after:\n");
	
	int min =a[0][0];
	
	int I = 0;
	int J = 0;;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
				I = i;
				J = j;
			}
		}
	}
	
	for (int j = 0; j < n; j++) {
		int t = a[m - 1][j];
		a[m - 1][j] = a[I][j];
		a[I][j] = t;
	}
	
	int mask = 0;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		if (i != m - 1) {
			printf("\n");
		}
	}
	
	return 0;
}
