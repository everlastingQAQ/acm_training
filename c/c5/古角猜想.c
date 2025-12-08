#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int mask = 1;

	while (n != 1) {
		int m = n;
		if (n % 2 == 0) {
			if (mask == 1) {
				n /= 2;
				printf("%d/2=%d", m, n);
				mask = 0;
			}else {
				n /= 2;
				printf("\n%d/2=%d", m, n);
			}
		}else if (n % 2 == 1) {
			if (mask == 1) {
				n = n * 3 + 1;
				printf("%d*3+1=%d", m, n);
				mask = 0;
			}else {
				n = n * 3 + 1;
				printf("\n%d*3+1=%d", m, n);
			}
		}
	}
	
	return 0;
}
