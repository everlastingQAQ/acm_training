#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int num[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	for (int i = n - 1; i > 0; i--) {
		int tag = i;
		for (int j = i - 1; j >= 0; j--) {
			if (num[tag] < num[j]) {
				tag = j;
			}
		}
		int t = num[i];
		num[i] = num[tag];
		num[tag] = t;
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
	
	return 0;
	
} 
