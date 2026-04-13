#include <stdio.h>

int main () 
{
	int n;
	scanf("%d", &n);
	
	int Prime[n + 1];
	
	for (int i = 2; i <= n; i++) {
		Prime[i] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		if (Prime[i] == 1) {
			for (int k = i * i; k <= n; k += i) {
				Prime[k] = 0;
			}
		}
	}

	int mask = 1;
	
	for (int i = 2; i <= n; i++) {
		if (Prime[i] != 0) {
			if (mask == 1) {
				printf("%d", i);
				mask = 0;
			}else {
				printf(" %d", i);
			}
		}
	}
	
	return 0;
	
}
