#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int mask = 1;
	int tag = 0;
	
	for (long long int cnt = 1; cnt <= n; cnt++) {
	    long long int res = 1;
	    
		for (long long int j = 1; j <= cnt; j++) {
			res *= 2;
		}
		
		res = res - 1;
		int isPrime = 1;
		
		long long int t = res;
		
		for (long long int i = 3; i * i < res || res == 1; i += 2) {
			if ( t % i == 0 || res == 1) {
				isPrime = 0;
				break;
			}
		}
		
		if (isPrime == 1 && mask == 1) {
			printf("%lld", res);
			mask = 0;
			tag = 1;
		}else if (isPrime == 1 && mask == 0) {
			printf("\n%lld", res);
		}
				
	}
	
	if (tag == 0) {
		printf("None");
	}
	return 0;
}
