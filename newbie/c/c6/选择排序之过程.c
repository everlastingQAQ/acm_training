#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int num[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	for (int i = 0; i < n - 1; i++) {
		int tag = i;
		for (int j = i + 1; j < n; j++) {
			if (num[j] < num[tag]) {
				tag = j;
			}
		}
		int t = num[i];
		num[i] = num[tag];
		num[tag] = t;
		for (int k = 0; k < n; k++) {
			printf("%d", num[k]);
			if (k < n - 1) {
				printf(" ");
			}
		}
		if (i < n - 2) {
			printf("\n");
		}
	}
	
	if (n == 1) {
		printf("%d", num[0]);
	}
	
	return 0;
	
} 
