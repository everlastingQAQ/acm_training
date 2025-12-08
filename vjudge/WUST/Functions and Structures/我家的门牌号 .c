#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int last = 1;
	int mine = last;
	
	while (1) {
		last = mine;
		while (1) {
			int sum = (1 + last) * last / 2;
			if (sum - 3 * mine == n) {
				goto f;
			}else if (sum - 3 * mine < n) {
				last++;
			}else if (sum - 3 * mine > n) {
				break;
			}
		}
		mine++;
	}
	
	f:
	
	printf("%d %d", mine, last);
	
	return 0;
}
