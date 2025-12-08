#include <stdio.h>

int main()
{
	int num = 0;
	int result = 0;
	int digital = 0;
	
	scanf("%d", &num);
	
	while (num > 0){
		digital = num % 10;
		result = result * 10 + digital; 
		num /= 10;
	}
	
	printf("%03d", result);
	
	return 0;
}
