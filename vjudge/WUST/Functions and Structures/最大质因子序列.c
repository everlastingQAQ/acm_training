#include <stdio.h>

void find_prime (int n, int prime[])
{
	for (int i = 0; i <= n; i++) {
		prime[i] = 1;
	}
	for (int i = 2; i * i <= n; i++) {
		if (prime[i]) {
			for (int k = i * i; k <= n; k += i) {
				prime[k] = 0;
			}
		}
	}
	prime[0] = 0;
	prime[1] = 0;
}

int main ()
{
	int m, n;
	scanf("%d %d", &m, &n);
	
	int Prime[n];
	find_prime(n, Prime);
	
	for (int i = m; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			if (i % j == 0 && Prime[j]) {
				printf("%d", j);
				if (i <= n - 1) {
					printf(",");
				}
				break;
			}
		}
	}
	
	return 0;
}
