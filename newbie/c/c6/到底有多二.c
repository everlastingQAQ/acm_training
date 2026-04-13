#include <stdio.h>

int main ()
{
	char s[52];
	gets(s);
	
	long double cnt = 0;
	long long mask = 0;
	
	for (int i = 0; i < 52; i++) {
		if (s[i] == '2') {
			cnt++;
		}
		if (s[i] == '\0' || i == 51) {
			mask = i;
			break;
		}
	}
	
	if ((s[mask - 1] - '0') % 2 == 0) {
		cnt *= 2;
	}
	
	if (s[0] == '-') {
		mask -= 1;
		printf("%.2Lf%%", cnt / mask * 100 * 1.5);
	}else {
		printf("%.2Lf%%", cnt / mask * 100);
	}
	
	return 0;
}
