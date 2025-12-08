#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	n += 1;
	
	int num [n];
	int mask = 1;
	
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == 1) {
			num [i] = 1;
			mask = i;
		}else {
			num [i] = num [i - 1] + num [i - 2];
			mask = i;
		}	
	}
	
	printf("%d", num[mask]);
	
	return 0;
	
}
