#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int num[n];
	int j = 2;
	
	for (int i = 0; i < n - 1; ) {
		if (n % j == 0) {
			j = num[i];
			i++;
		}
		j++;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (num[j] == num[j + 1] - 1) {
				
			}
		}
	}
}
