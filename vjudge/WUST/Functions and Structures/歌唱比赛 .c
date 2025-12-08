#include <stdio.h>

void delete_highest_lowest (int n, int m, int a[n][m])
{
	for (int i = 0; i < n; i++) {
		int max = a[i][0];
		int max_j = 0;
		
		int min = a[i][0];
		int min_j = 0;
		
		for (int j = 1; j < m; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
				max_j = j;
			}
			if (a[i][j] < min) {
				min = a[i][j];
				min_j = j;
			}
		}
		
		if (a[i][max_j] == a[i][min_j]) {
			a[i][max_j] = 0;
		}else {
		a[i][max_j] = 0;
		a[i][min_j] = 0;
		}
	}
}

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
	
	delete_highest_lowest(n, m, a);
	
	double result[n];
	
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += a[i][j];
		}
		result[i] = 1.0 * sum / (m - 2);
	}
	
	double max_result = result[0];
	for (int i = 0; i < n; i++) {
		if (result[i] > max_result) {
			max_result = result[i];
		}
	}
	
	printf("%.2f", max_result);
	
	return 0;
}
