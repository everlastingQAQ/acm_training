#include <stdio.h>

int main ()
{
	int n, u, d;
	scanf("%d %d %d", &n, &u, &d);
	
	int s = 0;
	int minute = 0;
	
	while (s <= n) {
		s += u;
		minute += 1;
		if (s >= n) {
			break;
		}
		s -= d;
		minute += 1; 
	}
	
	printf("%d", minute);
	
	return 0;
}
