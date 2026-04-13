#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    
    int mask = 1;
    int t = x;
    
    if (x < 0) {
    	printf("fu ");
    	x = - x;
    	t = - t;
	}
    
	while (t > 9) {
    	t /= 10;
    	mask *= 10;
	}
	
	do {
		int d = x / mask;
		
		switch (d) {
			case 0:
				printf("ling");
				break;
			case 1:
				printf("yi");
				break;
			case 2:
				printf("er");
				break;
			case 3:
				printf("san");
				break;
			case 4:
				printf("si");
				break;
			case 5:
				printf("wu");
				break;
			case 6:
				printf("liu");
				break;
			case 7:
				printf("qi");
				break;
			case 8:
				printf("ba");
				break;
			case 9:
				printf("jiu");
				break;								
		}
		
		x %= mask;
		mask /= 10;
		
		if (mask > 0) {
			printf(" ");
		}
		
	}while (mask > 0);
	

	return 0;
	
	}

