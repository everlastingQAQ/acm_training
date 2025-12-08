#include <stdio.h>

void findPrime (int n, int Prime[])
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
	findPrime(n, prime);
	
	for (int i = 4; i <= n; i += 2) {
		int j = 2;
		while (1) {
			if (prime[j] && prime[i - j]) {
				break;
			}
			j++;
		}
		printf("%d=%d+%d\n", i, j, i - j);
	}
	
	return 0;
}
