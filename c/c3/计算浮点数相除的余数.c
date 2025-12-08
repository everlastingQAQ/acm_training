#include <stdio.h>

int main()
{
	double a, b;
	
	scanf("%lf %lf", &a, &b);
	
	int k=0;
    double tag=0.0;
    double n=0.0;
    
    do{
    	n=a-k*b;
    	k++;
	}while (n>=0);
	
	double r=n+b;
	
	printf("%g", r);
	
	return 0;
}
