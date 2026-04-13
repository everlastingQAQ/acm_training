#include <stdio.h>

int main()
{
	int yr;
	scanf("%d", &yr);
	
	int mask1 = yr%400;
	int lpyr = 0;
	
	int mask2 = yr%4;
	int mask3 = yr%100;
	
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
		printf("%d is a leap year!", yr);
	}else {
		printf("%d isn't a leap year!", yr);
	}
	
	return 0;
	
}
