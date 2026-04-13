#include <stdio.h>

int main ()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	int s[n + 1];
	
	for (int i = 0; i < n + 1; i++) {
		s[i] = 0;
	}
	
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (j % i == 0) {
				s[j]++;
			}
		}
	}
	
	int mask = 1;
	
	for (int i = 1; i <= n; i++) {
		if (s[i] % 2 == 1) {
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
