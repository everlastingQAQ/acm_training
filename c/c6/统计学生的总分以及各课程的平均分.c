#include <stdio.h>

int main ()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	char name[n][100];
	int grade[n][m];
	
	int sum[n];
	
	for (int i = 0; i < n; i++) {
		sum[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%s", name[i]);
		for (int j = 0; j < m; j++) {
			scanf("%d", &grade[i][j]);
			sum[i] += grade[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%-8s", name[i]);
		printf("%6d", sum[i]);
		for (int j = 0; j < m; j++) {
			printf("%6d", grade[i][j]);
		}
		printf("\n");
	}
	
	double aver[m];
	
	for (int i = 0; i < m; i++) {
		aver[i] = 0;
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			aver[i] += grade[j][i];
		}
		aver[i] /= n;
	}
	
	printf("average score:");
	
	for (int i = 0; i < m; i++) {
		printf("%6.1f", aver[i]);
 	}	
	
	return 0;
	
}
