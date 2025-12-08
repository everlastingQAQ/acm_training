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
	
	int prime[100001];
	find_Prime(100001, prime);
	
	int a[n];
	int b[n];
	
	for (int i = 0; i < n; i++) {
		b[i] = -1;
	}
	
	int j = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (prime[a[i]]) {
			b[j] = a[i];
			j++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (b[i] != -1) {
			if (i == 0) {
				printf("%d", b[i]);
			}else {
				printf(" %d", b[i]);
			}
		}
	}
	
	return 0;
	
}
