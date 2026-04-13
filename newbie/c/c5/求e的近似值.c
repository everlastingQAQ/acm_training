#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	double e = 1;
	double res = 1;
	
	for (int num = 1; num <= n; num++) {
		res = 1;
		for (int t = 1; t <= num; t++) {
			res *= t;
		}
		e += 1.0 / res;
	}
	
	printf("%.8f", e);
	
	return 0;
}
