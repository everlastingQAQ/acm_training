#include <stdio.h>

int main () 
{
	int m, n;
	scanf("%d %d", &m, &n);
	
	int cnt = 0;
	int res = 0;
	
	if (m < 2) {
		m = 2;
	}
	
	for (int t = m; t <= n; t++) {
		int isPrime = 1;
		for (int x = 2; x < t; x++) {
			int rem = t % x;
			if (rem == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime == 1) {
			res += t;
			cnt++;
		}
	}
	
	printf("%d %d", cnt, res);
	
	return 0;
}
