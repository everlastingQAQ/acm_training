#include <stdio.h>

int main()
{
	double a, b;
	
	scanf("%lf %lf", &a, &b);
	
	double res1=a*b/100.0;
	
	double res2=res1+a;
	
	printf("%11.2f\n%11.2f\n%11.2f", a, res1, res2);
	
	return 0;
}
