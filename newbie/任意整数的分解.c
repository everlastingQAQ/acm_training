#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    
    int mask = 1;
    int t = x;
    
    while (t > 9) {
    	t /= 10;
    	mask *= 10;
	}
	
	do {
		int d = x / mask;
		
		printf("%d", d);
		
		x %= mask;
		mask /= 10;
		
		if (x > 0) {
			printf(" ");
		}
		
	}while (mask > 0);
	
	return 0;
	
	}

