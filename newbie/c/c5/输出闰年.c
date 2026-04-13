#include <stdio.h>

int main ()
{
	int yr;
	scanf("%d", &yr);
	
	if (yr <= 2000) {
		printf("Invalid year!");
	}
	
	int i = 2001;
	int mask = 1;
	
	while (i <= yr) {
 
		int mask1 = i % 400;
		int lpyr = 0;
		
		int mask2 = i % 4;
		int mask3 = i % 100;
		
		if (mask1 == 0) {
			lpyr = 1;
		}else {
			if (mask2 == 0) {
				if (mask3 != 0 ){
					lpyr = 1;
				}
			}
		}
		
		if (lpyr == 1) {
			if (mask == 1) {
				printf("%d", i);
				mask = 0;
			}else {
				printf("\n%d", i);
			}
		}
	
		i++;
		
	}
	
	if (mask == 1 && yr > 2000) {
		printf("None");
	}
	
	return 0;
	
}
