#include <stdio.h>

int main()
{
	int x, y1, y2, y3;
	scanf("%d %d %d %d", &x, &y1, &y2, &y3);
	
	int res = x - y1 - y2 - y3;
	
	if (res % 2 == 0) {
		printf("%d", res / 2 );
	}else {
		printf("%d", (res + 1) / 2 );
	}
	
	return 0;
}
