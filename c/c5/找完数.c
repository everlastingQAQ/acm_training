#include <stdio.h>

int main ()
{
	int min, max;
	scanf("%d %d", &min, &max);
	
	int mask = 1;
	int k = 1;
	int t = min;
	int sum = 0;
	
	for (int cnt = min; cnt <= max; cnt++) {
		int s = 0;
		for (int i = 1; i < t; i++) {
			if (t % i == 0) {
				s += i;
			}
		}
		if (s == t) {
			sum++;
		}
		t++;
	}
	
	mask = 1;
	k = 1;
	t = min;
	int SUM = 0;
	
	for (int cnt = min; cnt <= max; cnt++) {
		int s = 0;
		int temp = 0;
		for (int i = 1; i < t; i++) {
			if (t % i == 0) {
				s += i;
				temp++;
			}
		}
		int tag = 1;
		int TEMP = 0;
		if (s == t) {
			printf("%d = ", t);
			mask = 0;
			SUM++;
			for (int j = 1; j < t; j++) {
				if (t % j == 0) {
					if (tag == 1) {
						printf("%d", j);
						tag = 0;
						TEMP++;
					}else if (tag == 0 && TEMP == temp - 1) {
						if (SUM == sum) {
							printf(" + %d", j);
						}else {
							printf(" + %d\n", j);
						}
					}else if (tag == 0 && TEMP <= temp) {
						printf(" + %d", j);
						TEMP++;
					}
				}
			}
		}
		
		t++;
	}
	
	if (mask == 1) {
		printf("None");
	}
	
	return 0;
	
}
