#include <stdio.h>

int main()
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	
	int mask = 0;
	
	while (num2 != 0) {
		mask = num1 % num2;
		num1 = num2;
		num2 = mask;
	}
	
	printf("%d", num1);
	
	return 0;
}//解决了1 2的公约数是1的问题
