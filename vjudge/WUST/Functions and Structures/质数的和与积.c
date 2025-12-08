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
	int s;
	scanf("%d", &s);
	
	int Prime[10000];
	findPrime(s, Prime);
	
	int k = 0;
	int c[10000] = {0};
	for (int i = 0; i <= s / 2; i++) {
		if (Prime[i]) {
			int t = s - i;
			if (Prime[t] == 1 && i + t == s) {
				c[k] = i * t;
				k++;
			}
		}
	}
	
	int max = c[0];
	for (int i = 0; i <= k; i++) {
		if (c[i] > max) {
			max = c[i];
		}
	}
	
	printf("%d", max);
	
	return 0;
}
