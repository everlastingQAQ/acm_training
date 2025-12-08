#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int den = 1;
	double s = 0;
	int sign = 1; 
	
	for (int cnt = 0; cnt < n; cnt++) {
		s += sign * 1.0 / den;
		den += 3;
		sign = -sign;
	}
	
	printf("%.4f", s);
	
	return 0;
}
