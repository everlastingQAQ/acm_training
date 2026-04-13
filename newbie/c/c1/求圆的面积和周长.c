#include <stdio.h>

int main()
{
	double r;
	double s, c;
	const double K=3.140000;
	
	scanf("%lf", &r);
	
	s=K*r*r;
	c=2*K*r;
	
	printf("%lf\n%lf", s, c);
	
	return 0;
}
