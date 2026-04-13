#include <stdio.h>

void initialize_years(int year, int years[4]) 
{
	for (int i = 0; i < 4; i++) {
		years[i] = 0;
	}
	
	int i = 3;
	
	while (year > 0 && i >= 0) {
		years[i] = year % 10; 
		year /= 10;              
		i--;
	}
}

int main ()
{
	int y;
	scanf("%d", &y);

	int s[4];
	
	initialize_years(y, s);
	
	int n;
	scanf("%d", &n);
	
	int cnt = 0;
	
	while (1) {
		int mask = 1;
		int num[10] = {0};
		for (int i = 0; i < 4; i++) {
			int j = 0;
			for ( ; j < 10; ) {
				if (s[i] == j) {
					num[j]++;
					break;
				}else {
					j++;
				}
			}	
		}
		for (int k = 0; k < 10; k++) {
			if (n == 4) {
				if (num[k] != 0 && num[k] != 1) {
					mask = 0;
					break;
				}
			}else if (n == 3) {
				int cnt = 0;
				for (int l = 0; l < 10; l++) {
					if (num[l] == 2) {
						cnt++;
					}
				}
				if (cnt != 1) {
					mask = 0;
					break;
				}
			}else if (n == 2) {
				int tag = 0;
				for (int l = 0; l < 10; l++)
				if (num[l] == 0) {
					tag++;
				}
				if (tag != 8) {
					mask = 0;
					break;
				}
			}
		}
		if (mask == 0) {
			y += 1;
			cnt++;
			initialize_years(y, s);
		}else {
			break;
		}
	}
	
	printf("%d ", cnt);
	
	for (int i = 0; i < 4; i++) {
		printf("%d", s[i]);
	}
	
	return 0;
	
} 
