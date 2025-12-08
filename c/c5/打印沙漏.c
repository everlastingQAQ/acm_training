#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int sum = -1;
	int i = 2;
	
	while (n - sum - i >= 0) {
		sum += i;
		i += 4;
	}
	
	int k = i;
	int j = 1;
	int u = 1;
	
	while (k > 2) {
		
	int t = k / 2;
	int j = u;
	
		while (t > 2) {
			if (t == 3) {
				printf("*\n");
			}else {
				printf("*");
			}
			t--;
		}
		
		while (j > 0 && k > 6) {
			printf(" ");
			j--;
		}
		
	k -= 4;
	u += 1;

	}
	
	k = i;
	u -= 3;
	int p = 3;
	int m = 3;
	
	while (u >= 0) {
		
		j = u;
	 	p = m;
	 	
		while (j > 0) {
			printf(" ");
			j--;
		}
		
		while (p > 0) {
			if (p == 1) {
				printf("*\n");
			}else {
				printf("*");
			}
			p--;
		}
		
		m += 2;
		u -= 1;
	}

	int difference = n - sum;
	
	printf("%d", difference);
	
	return 0;
}
