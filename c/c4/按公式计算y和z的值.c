#include <stdio.h>
#include <math.h>

int main()
{
	double x = 0.0;
	scanf ("%lf", &x);
	
	double y, z;
	
	if (x >= 1 && x < 2) {
		y = x * x + 1.0;
		z = 3.0 * x + 5.0;
	}else if (x >= 2 && x <= 2.5) {
		y = x * x + 1.0;
		z = 2.0 * sin(x) - 1.0;
	}else if (x > 2.5 && x < 3) {
		y = x * x - 1.0;
		z = 2.0 * sin (x) - 1.0;
	}else if (x >= 3 && x < 5) {
		y = x * x - 1.0;
		z = sqrt (1.0 + x * x);
	}else if (x >= 5 && x < 8) {
		y = x * x - 1.0;
		z = x * x - 2 * x + 5;
	}
	
	printf("%lf\n%lf", y, z);
	
	return 0;
}
