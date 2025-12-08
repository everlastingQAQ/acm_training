#include <stdio.h>

int main ()
{
	int a, b;
	scanf("%d %d", &a, &b);
	
	int sum = 0;
	int mask = 1;
	
	for ( ; a <= b; a++) {
		int l = -1;
		int cnt = 0; 
		
		for (int i = 1; i <= 9; i++) {
			int A = a;
			A *= i;
			int n = A;
			int j = 0;
			int m = A;
			int k = 0;
			sum = 0;
			
			while (n > 0) {
				n /= 10;
				j++;
			}
			
			while (k < j) {
				int M = m;
				M %= 10;
				sum += M;
				m /= 10;
				k++;
			}
			
			if (sum == l || l == -1) {
				l = sum;
				cnt++;
				if (cnt == 9) {
					if (mask == 1) {
						printf("%d(%d)", a, sum);
						mask = 0;
					}else if (mask == 0) {
						printf("\n%d(%d)", a, sum);
					}
				}
			}else {
				break;
			}
		}			
	}
	
	if (mask == 1) {
		printf("None");
	}
	
	return 0;
	
}
