#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int num[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	int res;
	scanf("%d", &res);
	
	int a = 0;
	int b = n - 1;
	
	int mask = 0;
	
	while (a <= b) {
		
		int mid = a + (b - a) / 2;
		
		if (num[mid] == res) {
			printf("%d", mid);
			mask = 1;
			break;
		}else if (num[mid] < res) {
			a = mid + 1;
		}else {
			b = mid - 1;
		}
	}
	
	if (mask == 0) {
		printf("Not found");
	}
	
	return 0;
	
}
