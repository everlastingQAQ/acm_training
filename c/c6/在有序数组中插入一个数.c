#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int num[n + 1];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	int m;
	scanf("%d", &m);
	
	num[n] = m;
	
	for (int i = n - 1; i >= 0; i--) {
		if (num[i] > num[i + 1]) {
			int t = num[i + 1];
			num[i + 1] = num [i];
			num[i] = t;
		}else {
			break;
		}
	}
	
	int mask = 1;
	
	for (int i = 0; i <= n; i++) {
		if (mask == 1) {
			printf("%d", num[i]);
			mask = 0;
		}else {
			printf(" %d", num[i]);
		}
	}
	
	return 0;
	
}
