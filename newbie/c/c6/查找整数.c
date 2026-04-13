#include <stdio.h>

int main ()
{
	int n, x;
	scanf("%d %d", &n, &x);
	
	int s[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == x) {
			break;
		}
		cnt++;
	}
	
	if (cnt == n) {
		printf("Not Found");
	}else {
		printf("%d", cnt);
	}
	
	return 0;
}
