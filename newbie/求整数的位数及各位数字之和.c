#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int x = 1;
	int t = n;
	int sum = 0;
	int digit = 0;
	
	while (n > 0) {
		t %= 10;
		sum += t;
		n /= 10;
		t = n;
		digit++;
	}
	
	printf("%d %d", digit, sum);
	
	return 0;
}
