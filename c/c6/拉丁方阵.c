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
		if (i == n - 1) {
			break;
		}
		printf("\n");
	}
}

void intialize (int n, int s[n][n])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			s[i][j] = 0;
		}
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int a[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int s[n][n];
	
	intialize(n, s);
	
	for (int i = 0; i < n; i++) {
		int mask = 0;
		int k = 0;
		for (int j = 0; k < n; j++) {
			if (i + 1 == a[j] || mask == 1) {
				if (j > n - 1) {
					j = 0;
				}
				s[k][a[j] - 1] = a[i];
				mask = 1;
				k++;
			}
		}
	}
	
	printing(n, s);
	
	return 0;
	
}
