#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int i = 1;
	
	int tag = 1;
	
	for ( ; i <= n; i++) {
	    int j = 1;
		for ( ; j <= i; j++) {
			if (j == i) {
				printf("%d*%d=%-4d\n", i, j, j * i);
			}else {
				printf("%d*%d=%-4d", i, j, j * i);
			}
		}
	}
	
	return 0;
}
