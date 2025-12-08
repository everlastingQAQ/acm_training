#include <stdio.h>

void reverse(int a[], int l, int r) {
	while (l < r) {
		int t = a[l];
		a[l] = a[r];
		a[r] = t;
		l++;
		r--;
	}
}

int main () 
{
	int n, m;
	scanf("%d %d", &n, &m);
	m %= n;
	
	int s[n];
	for (int i = n - 1; i >= 0; i--) {
		scanf("%d", &s[i]);
	}
	
	reverse(s, 0, m - 1);
	reverse(s, m, n - 1);
	
	for (int i = 0; i < n; i++) {
		printf("%d ", s[i]);
	}
	
	return 0;
	
}
