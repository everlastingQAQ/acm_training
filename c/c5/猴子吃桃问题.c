#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int res = 1;
	
	for (int cnt = 1; cnt < n; cnt++) {
		res = (res + 1) * 2;
	}
	
	printf("%d", res);
	
	return 0;
}
