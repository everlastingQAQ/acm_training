#include <stdio.h>

int main()
{
	int num = 0;
	int res = 1;
	int fac = 1;
	
	scanf("%d", &num);
	
	while (fac <= num){
		res *= fac;
		fac++;
	}
	
	printf ("%d!=%d", num, res);
	
	return 0;
 } 
