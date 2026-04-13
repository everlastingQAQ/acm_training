#include <stdio.h>

int main()
{
	int num1, num2;
	
	printf("Please input two integers to calculate the average:");
	
	scanf("%d %d", &num1, &num2);
 	
 	printf("%f", (num1+num2)/2.0);
 	
	return 0;
}
