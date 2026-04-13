#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int cnt = 1;
	int sum = 0;
	int mask = 1;
	int k = -1;
	
	if (n != 13) {
		while (mask == 1) {
			
		int N = n;
		int m = n;
		int digit = 1;
		sum = 0;
		int i = 1;
		int j = 1;
		
		while (N > 1) {
			N /= 10;
			j++;
		}
		
		while (i <= j) {
			int M = m;
			M %= 10;
			sum += M;
			m /= 10;
			i++;
		}
		
		if (k != sum * 3 + 1) {
			sum = sum * 3 + 1;
			printf("%d:%d\n", cnt, sum);
			k = sum;
		}else {
			printf("%d:%d", cnt, k);
			mask = 0;
		}
		
		n = sum;
		cnt++;
	}
		
}else if (n == 13) {
	printf("1:13");
}
	
	return 0;
	                                                                                                               
}
