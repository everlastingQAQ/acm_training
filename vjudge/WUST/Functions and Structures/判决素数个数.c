#include <stdio.h>

void find_prime (int n, int prime[])
{
	for (int i = 0; i <= n; i++) {
		prime[i] = 1;
	}
	for (int i = 2; i <= n / i; i++) {
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
	int x, y;
	scanf("%d %d", &x, &y);
	
	int max;
	int min;
	if (x > y) {
		max = x;
		min = y;
	}else {
		max = y;
		min = x;
	}
	
	int prime[max + 1];
	find_prime(max, prime);
	
	int cnt = 0;
	for (int i = min; i <= max; i++) {
		if (prime[i]) {
			cnt++;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
