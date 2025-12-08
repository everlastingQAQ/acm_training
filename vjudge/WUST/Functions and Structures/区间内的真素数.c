#include <stdio.h>

void find_Prime (int n,int prime[n])
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

int fliping_number (int a)
{
	int t = a;
	int idx = 1;
	while (t >= 10) {
		t /= 10;
		idx *= 10;
	}
	
	int b = 0;
	int mask = 1;
	while (idx > 0) {
		b += a / idx * mask;
		a %= idx;
		idx /= 10;
		mask *= 10;
	}
	
	return b;
}

int main ()
{
	int m, n;
	scanf("%d %d", &m, &n);
	
	int max = n;
	for (int i = m; i <= n; i++) {
		if (fliping_number(i) > max) {
			max = fliping_number(i);
		}
	}

	int Prime[max];
	find_Prime(max, Prime);
	
	int mask = 0;
	for (int i = m; i <= n; i++) {
		if (Prime[i] == 1 && Prime[fliping_number(i)] == 1) {
			if (!mask) {
				printf("%d", i);
				mask = 1;
			}else {
				printf(",%d", i);
			}
		}
	}
	
	if (mask == 0) {
		printf("No");
	}
	
	return 0;
}
