#include <stdio.h>

int main ()
{
	long long n;
	scanf("%lld", &n);
	printf("%lld", n);
	
	long long m = n;
	long long cnt = 0;
	
	do {
		
		n = m;
		m = 0;
		
		long long t = n;
		long long j = 1;
		
		while (t >= 10) {
			t /= 10;
			j *= 10;		
		}	
		
		long long k = n;
		long long l = n;
		long long p = 1;
		
		while (j > 0) {
			long long l = k;
			l /= j;
			k %= j;
			m += l * p;
			j /= 10;
			p *= 10;
		}
		
		if (m == n) {
			break;
		}else {
			m += n;
			printf("--->%lld", m);
			cnt++;
		}
	}while (m != n);
	
	printf("\n%lld", cnt);
	
	return 0;
	
}
