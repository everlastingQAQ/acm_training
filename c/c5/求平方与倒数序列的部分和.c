#include <stdio.h>

int main ()
{
	double m, n;
	scanf("%lf %lf", &m, &n);
	
	double s = 0;
	
	for ( ; m <= n; m++) {
		s += m * m + 1.0 / m;
	}
	
	printf("%.6f", s);
	
	return 0;
}
