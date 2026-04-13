#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	
	scanf("%d", &n);
	
	double x=pow(2.0, 1.0/n);
	
	double res=(x-1.0)*100;
	
	printf("%.2f%%", res);
	
	return 0;
}
