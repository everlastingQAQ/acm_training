#include <stdio.h>

int main()
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	
	int mask = num1;
	int tag1, tag2;
	
	do{
		mask--;
		
		tag1 = num1 % mask;
		tag2 = num2 % mask;
		
	}while(tag1 != 0 || tag2 != 0);
	
	printf("%d", mask);
	
	return 0;
}
