#include <stdio.h>

int main()
{
	int a, b, c;
	
	scanf("%d %d", &a, &b);
	
	int rem=a%b;
	int t=a/b;
	
	if (rem==0)
	   printf("%d", t);
	   
	else 
	   printf("%d", t+1);
	
	return 0;
	
}
