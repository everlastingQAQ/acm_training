#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int q[1001] = {0};
	
	for (int i = 0; i < n; i++) {
		int p;
		scanf("%d", &p);
		
		for (int j = 0; j < p; j++) {
			int k;
			scanf("%d", &k);
			q[k]++;
		}
		
	}
	
	int max = 1000;
	
	for (int i = 1000; i >= 0; i--) {
		if (q[i] > q[max]) {
			max = i;
		}
	}
	
	printf("%d %d", max, q[max]);
	
	return 0;
}
