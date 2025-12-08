#include <stdio.h>

int main()
{
	int a, b, c, max;
	
	printf("Please input three nums:");
	
	scanf("%d %d %d", &a, &b, &c);
	
	if (a>b){
	
	   if (a>c) 
	    max=a;
	   else 
	    max=b;	
	}
	else{
	
		if (b>c) 
		 max=b;
		else 
		 max=c;
	}
	
	printf("The max num is %d", max);
	
	return 0;
} 
