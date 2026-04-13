#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int num[100];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (num[j] > num[j + 1]) {
				int t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d", num[i]);
		if (i != n - 1) {
			printf(" ");
		} 
	}
	
	return 0;
	
}
