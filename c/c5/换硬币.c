#include <stdio.h>

int main ()
{
	int x;
	scanf("%d", &x);
	
	int one;
	int two;
	int five;
	int mask = 0;
	
	for (five = x / 5; five != 0; five--) {
		for (two = x / 2; two != 0; two--) {
			for (one = x - 1; one != 0; one--) {
				if (one + two * 2 + five * 5 == x) {
					int cnt = one + two + five;
					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", five, two, one, cnt);
					mask++;
				}
			}
		}
	}
	
	printf("count = %d", mask);
	
	return 0;
}//ʷɽ 
