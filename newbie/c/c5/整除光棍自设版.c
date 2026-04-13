#include <stdio.h>

int main ()
{
	int x;
	scanf("%d", &x);
	
	unsigned long long a = 1;
	int b = 0;
	int cnt = 1;
	
	while (a < x) {
		a = a * 10 + 1;
		cnt++;
	}
	
	b = a / x;
	printf("%d", b);
	
	unsigned long long t = a % x;
	
	while (t != 0) {
		t = t * 10 + 1;
		int res = t / x;
		printf("%d", res);
		cnt++;
		t %= x;
	}
	
	printf(" %d", cnt);
	
	return 0;
}
