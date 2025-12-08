#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int a = 0;
	int b = 0;
	int c = 0;
	
	for (int cnt = 1; cnt <= n; cnt++) {
		int num = 0;
		scanf("%d", &num);
		if (num >= 85) {
			a += 1;
		}else if (num >= 60 && num < 85) {
			b += 1;
		}else if (num < 60) {
			c += 1;
		}
	}
	
	printf("%d %d %d", a, b, c);
	
	return 0;
}
