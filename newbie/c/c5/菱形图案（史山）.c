#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	n += 1;
	
	int cnt = 1;
	int CNT = 1;
	
	for (int s = n - 1; s > 0; s--) {
		for (int cnt_s = s; cnt_s > 1; cnt_s--) {
			printf(" ");
		}
		
		int cnt_q = 1;
		
		for ( ; cnt_q <= cnt; cnt_q++) {
			if (cnt_q == cnt) {
				printf("*\n");
			}else {
				printf("*");
			}
		}
	
		cnt += 2;
	}
	
	int CNT_S = 1;
	int mask = 0;
	int tag = 1;
	
	for (int S = n - 2; S > 0; S--) {		
		int cnt_S = 1;
		for (int cnt_S = 1 ; cnt_S <= CNT_S; cnt_S++) {
			mask++;
			if (cnt_S == 1 && tag == 0) {
				printf("\n ");
			}else {
				printf(" ");
			}	
		}

		int cnt_Q = 2 * (n - 1) - 3;
		
		for ( ; cnt_Q > 0; cnt_Q--) {
			if (cnt_Q == 1) {
				printf("*");
			}else {
				printf("*");
			}
		} 
		
		CNT += 1;
		n--;
		CNT_S++;
		tag = 0;
	}
	
	return 0;
}
