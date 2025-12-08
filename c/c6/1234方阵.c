#include <stdio.h>

void printing (int n, int s[n][n])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", s[i][j]);
			if (j < n - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int s[n][n];
	
	for (int i = 0; i < n; i++) {
		s[i][i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		s[n - 1 - i][i] = 0;
	}
	
	int cnt = n - 2;
	int k = cnt;
	int l = cnt;
	int J = 1;
	
	for (int i = 0; k > 0; i++) {
		l = k;
		int j = J;
		while (l > 0) {
			s[i][j] = 1;
			l--;
			j++;
		}
		k -= 2;
		J += 1;
	}
	
	cnt = n - 2;
	k = cnt;
	l = cnt;
	int I = 1;
	
	for (int j = 0; k > 0; j++) {
		l = k;
		int i = I;
		while (l > 0) {
			s[i][j] = 2;
			l--;
			i++;
		}
		k -= 2;
		I += 1;
	}
	
	cnt = n - 2;
	k = cnt;
	l = cnt;
	J = 1;
	
	for (int i = n - 1; k > 0; i--) {
		l = k;
		int j = J;
		while (l > 0) {
			s[i][j] = 3;
			l--;
			j++;
		}
		k -= 2;
		J += 1;
	}
	
	cnt = n - 2;
	k = cnt;
	l = cnt;
	I = 1;
	
	for (int j = n - 1; k > 0; j--) {
		l = k;
		int i = I;
		while (l > 0) {
			s[i][j] = 4;
			l--;
			i++;
		}
		k -= 2;
		I += 1;
	}
	
	printing(n, s);
	
	return 0;
	
}
