#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int cnt = 1;
	int s = 0;
	
	do {
		int count = 1;
		int cur = 1;
		while (count <= cnt) {
			cur = count * cur;
			count++; 
			} 
		s += cur;
		cnt++;
	} while (cnt <= n);
	
	printf("%d", s);
	
	return 0;
 } 
