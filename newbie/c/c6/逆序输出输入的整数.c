#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int num [n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num [i]);
	}
	
	int mask = 1;
	
	for (int j = n - 1; j >= 0; j--) {
		if (mask == 1) {
			printf("%d", num [j]);
			mask = 0;
		}else {
			printf(" %d", num [j]);
		}
	}
	
	return 0;
	
}
