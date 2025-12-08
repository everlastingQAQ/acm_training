#include <stdio.h>

int main()
{
	double a, b, c, d;
	
	scanf("%lf %lf %lf %lf,", &a, &b, &c, &d);
	
	double p=2.5*a+1.7*b+2*c+1.2*d;
	
	printf("%.2f", p);
	
	return 0;
}
