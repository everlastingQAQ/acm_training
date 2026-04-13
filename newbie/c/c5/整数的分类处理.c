#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int A1max = 0;
	int A2 = 0;
	double A3sum = 0;
	int A3 = 0;
	int mask1 = 0;
	int mask2 = 0;
	int mask3 = 0;
	
	for (int cnt = 1; cnt <= n; cnt++) {
		int a;
		scanf("%d", &a);
		if (a % 3 == 0 && A1max < a) {
			A1max = a;
			mask1 = 1;
		}else if (a % 3 == 1) {
			A2++;
			mask2 = 1;
		}else if (a % 3 == 2) {
			A3sum += a;
			A3++;
			mask3 = 1;
		}
	}
	
	if (mask1 == 1) {
		if (mask2 == 1) {
			if (mask3 == 1) {
				printf("%d %d %.1f", A1max, A2, A3sum / A3);
			}else {
				printf("%d %d NONE", A1max, A2);
			}
		}else if (mask3 == 1) {
			printf("%d NONE %.1f", A1max, A3sum / A3);
		}else {
			printf("%d NONE NONE", A1max);
		}
	}else if (mask2 == 1) {
			if (mask3 == 1) {
				printf("NONE %d %.1f", A2, A3sum / A3);
			}else {
				printf("NONE %d NONE", A2);
			}
		}else if (mask3 == 1) {
			printf("NONE NONE %.1f", A3sum / A3);
		}else {
			printf("NONE NONE NONE");
		}
	
	return 0;
}
