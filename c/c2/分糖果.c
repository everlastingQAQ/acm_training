#include <stdio.h>

int main ()
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	
	int a = x / 3;
	x = a;
	y += a;
	z += a;
	
	int b = y / 3;
	x += b;
	y = b;
	z += b;
	
	int c = z / 3;
	x += c;
	y += c;
	z = c;
	
	printf("%d %d %d", x, y, z);
	
	return 0;
}
