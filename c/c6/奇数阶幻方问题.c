#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int s[n][n];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			s[i][j] = 0;
		}
	}
	
	int i = 0;
	int j = (n - 1) / 2;
	
	for (int k = 1; k <= n * n; k++) {
		s[i][j] = k;
		int I = i;
		int J = j;
		i -= 1;
		j += 1;

		if (i < 0) {
			i = n - 1;
		}
		if (j > n - 1) {
			j = 0;	
		}
		if (s[i][j] != 0) {
			i = I + 1;
			j = J;
		}
		
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", s[i][j]);
			if (j == n - 1) {
				printf("\n");
			}
		}
	}
	
	return 0;
}
