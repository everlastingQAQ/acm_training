#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int mask = 1;
	
	for (int x = 1; x * x <= n; x++) {
		for (int y = x; y * y <= n; y++) {
			if (x * x + y * y == n) {
				if (mask == 1) {
					printf("%d %d", x, y);
					mask = 0;
				}else {
					printf("\n%d %d", x, y);
				}
			}
		}
	}
	
	if (mask == 1) {
		printf("No Solution");
	}
	
	return 0;
}
