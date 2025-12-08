#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	double sum = 0.0;
    int cnt = 0;
	double i = 2.0;
	double j = 1.0;
	double k = 2.0;
	
	for (cnt = 0; cnt < n; cnt++) {
		sum += i / j;
		k = i;
		i += j;
		j = k; 
	}
	
	printf("%lf", sum);
	
	return 0;
}
