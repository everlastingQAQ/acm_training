#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int tag = n % 5;
	
	switch (tag) {
		case 1:
		case 2:
		case 3:
			printf("Fishing in day %d", n);
		    break;
		    
		default:
			printf("Drying in day %d", n);
	}
	
	return 0;
	
}
