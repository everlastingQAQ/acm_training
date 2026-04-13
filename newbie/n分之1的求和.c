#include <stdio.h>

int main()
{
	int x;
	
	scanf("%d", &x);
	
	int n;
	double res=0.000000;
	
	for(n = 1; n <= x; n++){
		res += 1.000000/n;
	}
	
	printf("%lf", res);
	
	return 0;
 } 
