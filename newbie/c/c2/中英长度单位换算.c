#include <stdio.h>

int main()
{
	int cm, foot, inch;
	
	scanf("%d", &cm);
	
    int t=cm/30.48;
	
	double n=cm/30.48;
	
	foot=t;
	
	inch=(n-t)*12;
	
	printf("%d %d", foot, inch)	;
	
	return 0;
}
