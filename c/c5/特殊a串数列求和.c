#include <stdio.h>

int main ()
{
	int a, n;
	scanf("%d %d", &a, &n);
	
	int temp = a;
	int res = a;
	
	for (int cnt = 0; cnt < n - 1; cnt++) {
		temp = temp * 10 + a;
		res += temp;
		
	}
	
	printf("%d", res);
	
	return 0;
}
