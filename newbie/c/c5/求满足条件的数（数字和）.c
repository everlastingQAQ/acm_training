#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int mask = 0;
	int tag = 0;
	
	int i = 1;
	
	while (i <= n) {
	
		int t = i;
		int j = 1;
		
		while (t >= 10) {
			t /= 10;
			j *= 10;		
		}
		
		int sum = 0;
		int k = i;
		int l = i;
		
		while (j > 0) {
			int k = l;
			k /= j;
			sum += k;
			l %= j;
			j /= 10;
		}
		
		if (sum == 15) {
			if (mask < 7) {
				printf("%6d", i);
				mask++;
				tag = 1;
			}else {
				printf("%6d\n", i);
				mask = 0;
			}
		}
		
		i++;
	}
	
	if (tag == 0) {
		printf("None");
	}
	
	return 0;
	
}
