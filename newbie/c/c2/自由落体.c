#include <stdio.h>

int main ()
{
	int t;
	scanf("%d", &t);
	
	int h = 10 * t * t / 2;
	
	if (h > 2000) {
		printf("2000");
	}else {
		printf("%d", h);
	}
	
	return 0;
}
