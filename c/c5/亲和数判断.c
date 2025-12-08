#include <stdio.h>

int main ()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int sum1 = 0;
	int sum2 = 0;
	
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum1 += i;
		}
	}
	
	for (int j = 1; j < m; j++) {
		if (m % j == 0) {
			sum2 += j;
		}
	}
	
	if (sum1 == m && sum2 == n) {
		printf("YES");
	}else {
		printf("NO");
	}
	
	return 0;
}
