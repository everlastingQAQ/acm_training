#include <stdio.h>

int main ()
{
	int m;
	scanf("%d", &m);
	
	int cnt = 0;
	int t = m - 1;
	int tag = 1;
	
	while (cnt < 10) {
		int mask = 0;
		for (int i = 2; i <= t; i++) {
			int temp = t % i;
			if (temp == 0) {
				break;
			}else {
				mask++;
			}
		}
		if (mask == t - 2) {
			cnt++;
			if (tag == 1) {
				printf("%d", t);
				tag = 0;
			}else {
				printf(" %d", t);
			}
		}
		
		t--;
	}
	
	return 0;
}
