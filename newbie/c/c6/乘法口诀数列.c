#include <stdio.h>

int power (int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}

int find_digit (int n)
{
	if (n == 0) {
		return 1;
	}
	
	int digit = 0;
	
	while (n > 0) {
		n /= 10;
		digit++;
	}
	
	return digit;
}

int main ()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int s[c + 1];
	s[0] = a;
	s[1] = b;
	
	int i = 1;
	int l = 1;
	while (i < c) {
		long long j = s[l] * s[l - 1];
		int digits = find_digit (j) - 1;
		long long temp = power (10, digits);
		while (temp > 0 && i < c) {
			int digit = j / temp;
			s[++i] = digit;
			j %= temp;
			temp /= 10;
		}
		l++;
	}
	
	for (int i = 0; i < c; i++) {
		printf("%d", s[i]);
		if (i < c - 1) {
			printf(" ");
		}
	}
	
	return 0;
}
