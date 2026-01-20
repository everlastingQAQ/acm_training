#include <stdio.h>

int main ()
{
	long long n, q, k;
	scanf("%lld %lld %lld", &n, &q, &k);
	
	long long s[n + 1];
	for (long long i = 1; i < n + 1; i++) {
		scanf("%lld", &s[i]);
	}
	
	long long cnt[q];
	long long l[q];
	long long r[q];
	
	for (long long i = 0; i < q; i++) {
		scanf("%lld %lld", &l[i], &r[i]);
	}
	
	for (long long i = 0; i < q; i++) {
		cnt[i] = 0;
		for (long long j = l[i]; j <= r[i]; j++) {
			long long sum = 0;
			for (long long m = j; m <= r[i]; m++) {
				sum += s[m];
				if (sum >= k) {
					cnt[i]++;
				}
			}
		}
	}
	
	
	for (long long i = 0; i < q; i++) {
		printf("%lld", cnt[i]);
		if (i < q - 1) {
			printf("\n");
		}
	}
	
	return 0;
}
