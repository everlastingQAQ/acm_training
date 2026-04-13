#include <stdio.h>

void intialize (int n, int s[2 * n + 1])
{
	for (int i = 0; i < 2 * n + 1; i++) {
		s[i] = i;
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int s[2 * n + 1];
	intialize (n, s);
	
	int a[2 * n + 1];
	
	int cnt = 0;
	
	do {
		
		for (int i = 1; i <= n; i++) {
			a[2 * i] = s[i];
			a[2 * i - 1] = s[n + i];
		}
		
		for (int i = 1; i <= 2 * n; i++) {
			s[i] = a[i];
		}
		
		cnt++;
		
	}while (a[1] != 1);
	
	printf("%d", cnt);
	
	return 0;
	
} 
