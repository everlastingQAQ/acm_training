#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	double sum = 0;
	
	for (int cnt = 1; cnt <= n; cnt++) {
		double a = 0;
		scanf("%lf", &a);
		a = 1.0 / a;
		sum += a;
	}
	
	double res = n / sum;
	
	printf("%.2f", res);
	
	return 0;
}
