#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int i = 1;
	int j = 0;
	int k;
	int cnt;
	int p = 1;
	
	for (cnt = 0; cnt < n; cnt++) { 
		printf("%10d", i);
		if (p % 5 == 0 && p!= 0) {
			printf("\n");
		}
		k = i;
		i = j + i;
		j = k;
		p++;
	}
	
	return 0;
 } 
