#include <stdio.h>
#include <math.h>

int main()
{
	double n;
	char c;
	scanf("%lf %c", &n, &c);
	
	int cnt = 0;
	double mask = 0.0;
	int tag = round (n / 2);
	
	while (cnt <= n) {
		cnt++;
		printf("%c", c);
		if (cnt == n) {
			printf("\n");
			cnt = 0;
			mask ++;
			if (mask == tag) {
				break;
			}
		} 
	}
	
	return 0;
}
