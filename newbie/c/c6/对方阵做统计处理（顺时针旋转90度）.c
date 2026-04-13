#include <stdio.h>

void Traverse(int n, int s[n][n])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &s[i][j]);
		}
	}
}

int sumD(int n, int s[n][n])
{
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		sum += s[i][i];
	}
	
	for (int i = 0; i < n; i++) {
		sum += s[n - 1 - i][i];
	}
	
	if (n % 2 != 0) {
		sum -= s[(n - 1) / 2][(n - 1) / 2];
	}
	
	return sum;
	
}

int multiple(int n, int s[n][n])
{
	int m = 1;
	
	for (int i = 0; i < n; i += 2) {
		m *= s[i][i]; 
	}
	
	for (int j = 0; j < n; j += 2) {
		if ((n - 1 - j) % 2 == 0) {
			m *= s[n - 1 - j][j];
		} 
	}
	
	return m;
	
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int s[n][n];
	Traverse(n, s);
	
	printf("%d %d\n", sumD(n, s), multiple(n,s));
	
	int p[n][n];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			p[j][n - 1 - i] = s[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", p[i][j]);
			if (j < n - 1) {
				printf(" ");
			}
		}
		if (i < n - 1) {
			printf("\n");
		}
	}
	
	return 0;
	
}
