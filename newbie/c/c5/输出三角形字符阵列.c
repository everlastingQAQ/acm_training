#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	char chr = 'A';
	int cnt = 0;
	int N = n;
	int mask = 1;
	
	while (cnt <= n) {
		
		if (N == 1 && mask == 1) {
			printf("%c\n", chr);	
		}else if (N > 1 && mask == 1) {
			printf("%c ", chr);	
		}else if (N == 1 && mask == 0) {
			printf("%c", chr);
		}
		
		chr++;
		N--;
		
		if (N == 0) {
			n -= 1;
			N = n;
			cnt = 0;
		} 
		
		if (N == 1 && n == 1) {
			mask = 0;
		} 
		
		cnt++;
		
	}
	
	return 0;
	
}
