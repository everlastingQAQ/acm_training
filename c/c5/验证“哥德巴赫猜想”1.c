#include <stdio.h>

int main ()
{
	long int n;
	scanf("%ld", &n);
	
	long int b = 0;
	long int num1 = 0;
	long int num2 = 0;
	
	for (long int t = 2; t <= n; t++) {
		int isPrime = 1;
		
		for (long int i = 2; i * i < t; i++) {
			if (t % i == 0 && t != 2) {
				isPrime = 0;
				break;
			}
		}
		
		if (isPrime == 1) {
			num1 = t;
			b = n - t;
		}
		
		int isprime = 1;
		
		for (long int j = 2; j * j < b; j++) {
			if (b % j == 0 && b != 2) {
				isprime = 0;
				break;
			}
		}
		
		if (isprime == 1) {
			num2 = b;
			break;
		}
	}
	
	printf("%ld = %ld + %ld", n, num1, num2);
	
	return 0;
	
}
