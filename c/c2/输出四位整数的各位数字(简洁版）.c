#include <stdio.h>

int main()
{
	int num = 0;
	
	scanf("%d", &num);
	
	int d = num % 10;
	int c = (num / 10) % 10;
	int b = (num / 100) % 10;
	int a = (num / 1000) % 10;
	
	printf("%d=%d+%d*10+%d*100+%d*1000", num, d, c, b, a);
	
	return 0;
}
