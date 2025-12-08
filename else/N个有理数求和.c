#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	long long a;
	long long b;
	long long res = 0;
	long long crt = 0;
	
	for (int cnt = 0; cnt < n; cnt++) {
		scanf("%lld/%lld", &a, &b);
	    crt = a / b;
		res += crt;
	}
	
	printf("%lld", res);
	
	return 0;
}
