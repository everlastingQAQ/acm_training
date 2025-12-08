#include <stdio.h>

void find_Prime (int n, int Prime[])
{	
	for (int i = 2; i <= n; i++) {
		Prime[i] = 1;
	}
	
	for (int i = 2; i * i <= n; i++) {
		if (Prime[i] == 1) {
			for (int k = i * i; k <= n; k += i) {
				Prime[k] = 0;
			}
		}
	}
	
	Prime[0] = 0;
	Prime[1] = 0;
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int prime[n];
	find_Prime(n, prime);
	
	int mask = 0;
	for (int i = 3; i <= n - 2; i++) {
		if (prime[i] && prime[i + 2]) {
			printf("%d %d\n", i, i + 2);
			mask = 1;
		}
	}
	
	if (!mask) {
		printf("empty");
	}
	
	return 0;
}
