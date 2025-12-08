#include <stdio.h>

int main () 
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int h[n + 1];
	
	for (int i = 0; i <= n; i++) {
		h[i] = 1;
	}
	
	h[0] = 0;
	h[1] = 0;
	
	int i = 2;
	int j = 1;
	int s = 1;
	
	while (s <= m * n) {
		j += i;
		s += i;
		i++;
		if (s > m * n) {
			break;
		}
		if (j > n) {
			j %= n;
			if (j == 0) {
				j = n;
			}
		}
		h[j] = 0;
	}
	
	int mask = 1;
	
	for (int i = 0; i <= n; i++) {
		if (h[i] == 1) {
			if (mask == 1) {
				printf("%d", i);
				mask = 0;
			}else {
				printf(" %d", i);
			}
		}
	}
	
	if (mask == 1) {
		printf("No choice");
	}
	
	return 0;
	
}
