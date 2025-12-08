#include <stdio.h>

int main ()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int a[n][m];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == m - 1) {
				printf("%d", a[i][j]);
			}else {
				printf("%d ", a[i][j]);
			} 
		}
		printf("\n");
	}
	
	int b[m][n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[j][i];
			if (j == n - 1) {
				printf("%d", b[i][j]);
			}else {
				printf("%d ", b[i][j]);
			} 
		}
		printf("\n");
	}	
	
	return 0;
		
}
