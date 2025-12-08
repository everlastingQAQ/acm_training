#include <stdio.h>

int main ()
{
	double x;
	scanf("%lf", &x);
	
	double res = 1;
	int t = x;
	double temp = 1;
	int cnt = 1;
	
	while (temp >= 0.000001) {
		temp = temp * x / cnt;
		res += temp;
		cnt++;
	}
	
	printf("%.5f", res);
	
	return 0;
}
