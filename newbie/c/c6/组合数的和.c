#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int s[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	
	int count = 1;
	for (int i = 2; i <= n; i++) {
		count *= i;
	}
	
	int a[count];
	int k = 0;
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				a[k] = s[i] * 10 + s[j];
				sum += a[k];
				k++;
			}
		}
	}
	
	printf("%d", sum);
	
	return 0;
}
