#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int num [n];

	for (int i = 0; i < n; i++) {
		if (i == 0 || i == 1) {
			num [i] = 1; 
		}else {
			num [i] = num [i - 1] + num [i - 2];
		}	
	}
	
	int mask = 1;
		
	for(int j = 0; j < n; j++) {
		if (mask % 5 == 0) {
			if (mask == n) {
				printf("%10d", num [j]);
			}else {
				printf("%10d\n", num [j]);
				mask++;
			}
		}else {
			printf("%10d", num [j]);
			mask++;
		}
	}
	
	return 0;
	
}
