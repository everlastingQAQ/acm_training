#include <stdio.h>

void find_Palindrome (int n, int Palindrome[])
{
	for (int i = 0; i <= n; i++) {
		Palindrome[i] = 0;
	}
	
	for (int i = 11; i <= n; i++) {
		int t = i;
		int a = i;
		int idx = 1;
		while (t > 9) {
			t /= 10;
			idx *= 10;
		}
		int f = 0;
		int mask = 1;
		while (idx > 0) {
			f += a / idx * mask;
			a %= idx;
			idx /= 10;
			mask *= 10;
		}
		if (f == i) {
			Palindrome[i] = 1;
		}
	}
}

void find_Prime (int n, int Prime[])
{	
	for (int i = 2; i <= n; i++) {
		Prime[i] = 1;
	}
	
	for (int i = 2; i * i <= n; i++) {
		if (Prime[i] == 1) {
			for (int k = i * i; k <= n; k += i) {
				Prime[k] = 0;
			}
		}
	}
	
	Prime[0] = 0;
	Prime[1] = 0;
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int prime[n];
	int palindrome[n];
	
	find_Prime(n, prime);
	find_Palindrome(n, palindrome);
	
	int cnt = 0;
	for (int i = 11; i <= n; i++) {
		if (prime[i] && palindrome[i]){
			cnt++;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
