#include <stdio.h>

int main ()
{
	long long a, n;
	scanf("%lld %lld", &a, &n);
	
	long long temp = a;
	long long res = a;
	
	for (long long cnt = 0; cnt < n - 1; cnt++) {
		temp = temp * 10 + a;
		res += temp;
		
	}
	
	printf("%lld", res);
	
	return 0;
}
