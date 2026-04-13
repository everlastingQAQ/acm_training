#include <stdio.h>

void find(int m, int n, int a[m], int b[n], int s[42])
{
	int cnt = 0;
	
	for (int i = 0; i < m; i++) {
		
		int mask = 0;
		for (int j = 0; j < n; j++) {
			if (a[i] == b[j]) {
				mask = 1;
				break;
			}
		}
		if (mask == 0) {
			s[cnt++] = a[i];
		}
	}
	
	for (int i = 0; i < n; i++) {
		
		int mask = 0;
		for (int j = 0; j < m; j++) {
			if (b[i] == a[j]) {
				mask = 1;
				break;
			}
		}
		if (mask == 0) {
			s[cnt++] = b[i];
		}
	}
}

void printing (int a[42])
{
	int s[42];
	
	for (int i = 0; i < 42; i++) {
		s[i] = -1;
	}
	
	for (int i = 0; i < 42 && a[i] != -1; i++) {
		if (s[i] == -1) {
			printf("%d ", a[i]);
			for (int j = i; j < 42 && a[j] != -1; j++) {
				if (a[j] == a[i]) {
					s[j] = 0;
				}
			}
		}	
	}	
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int m;
	scanf("%d", &m);
	
	int b[m];
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	
	int s[42];
	
	for (int i = 0; i < 42; i++) {
		s[i] = -1;
	}
	
	find(n, m, a, b, s);
	
	printing(s);
	
	return 0;
	
} 
