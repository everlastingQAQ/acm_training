#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int cnt = 0;
	double res = 0.0;
	int i = 1;
	int sign = 1;
	
	for (cnt = 0; cnt < 2*n; cnt++) {
		res += sign * 1.0 / i;
		i += 2;
		sign = -sign;
	}
	
	printf("%lf", res*4.0);
	
	return 0;
}
