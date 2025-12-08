#include <stdio.h>

long long int power (int n, int m)
{
	int res = 1;
	for (int i = 0; i < m; i++) {
		res *= n;	
	}
	return res;
}

int main ()
{
	int s[30] = {0};
	
	long long int sum = 0;	
	int i = 0;
	while (scanf("%d", &s[i]) == 1) {
		sum += s[i];
		i++;
		char c = getchar();
		if (c == '\n') {
			break;
		}
	}
	
	long long int result = sum * power(2, i - 1);
	
	printf("%lld", result);
	
	return 0;
}
