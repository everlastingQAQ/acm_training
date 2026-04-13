#include <stdio.h>

int main()
{
	int a, b, c, d;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	int sum=a+b+c+d;
	double aver=(a+b+c+d)/4.00;
	
	printf("Sum = %d\nAverage = %.2f", sum, aver);
	
	return 0;
}
