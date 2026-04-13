#include <stdio.h>

int main()
{
	int num;
	
	scanf("%d", &num);
	
	int a=num/1000, 
	    b=num/100-a*10, 
	    c=num/10-a*100-b*10,
	    d=num-a*1000-b*100-c*10;
	
	printf("%d=%d+%d*10+%d*100+%d*1000", num, d, c, b, a);
	
	return 0;
 } 
