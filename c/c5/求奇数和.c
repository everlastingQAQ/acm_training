#include <stdio.h>

int main ()
{
	int num = 1;
	int temp = 0;
	int res = 0;
	
	while (num > 0) {
		scanf("%d", &num);
		if (num > 0) {
			temp = num % 2;
			if (temp != 0) {
				res += num;
		    }	
		}
		
	}
	
	printf("%d", res);
	
	return 0;
}
