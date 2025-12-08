#include <stdio.h>

int main()
{
	int min, max;
	scanf("%d %d", &min, &max);
	
	int tag = min;
	int mask = 10;
	int test = 0;
	int isfirst = 1;
	
	for (tag = min; tag <= max; tag++) {
		int t = tag * tag;
		int p = tag;
	    mask = 1;
		while (p > 0) {
			p /= 10;
			mask *= 10;
		}
		int cur = t % mask;
		if (cur == tag) {
			if (isfirst == 1) {
				printf("%d", tag);
				test = 1;
				isfirst = 0;
			}else{
			printf(" %d", tag);
		}
	}
	}
	
	if (test == 0) {
		printf("No exist");
	}

	return 0;
}
