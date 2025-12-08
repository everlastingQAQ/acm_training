#include <stdio.h>

int main ()
{
	int yr0, yr;
	scanf("%d %d", &yr0, &yr);
	
	int cnt = 0;
	int a[1500] = {0};
	
	while (yr0 <= yr) {
		
		int mask1 = yr0 % 400;
		int lpyr = 0;
		
		int mask2 = yr0 % 4;
		int mask3 = yr0 % 100;
		
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
			a[cnt] = yr0;
			cnt++;
		}
		
		yr0++;
		
	}

	printf("%d\n", cnt);
	
	for (int i = 0; i < cnt; i++) {
		printf("%d", a[i]);
		if (i < cnt - 1) {
			printf(" ");
		}
	}
	
	return 0;
	
}
