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
	int max, cnt;
	scanf("%d %d", &max, &cnt);
		
	int isPrime[10001];
	findPrime(max, isPrime);
	
	int sum = 0;
	int mask = 0;
	
	for (int i = max; i > 0 && mask < cnt; i--) {
		if (isPrime[i] == 1) {
			sum += i;
			if (mask == 0) {
				printf("%d", i);
			}else {
				printf("+%d", i);
			}
			mask++;
		}
	}
	
	printf("=%d", sum);
	
	return 0;
}
