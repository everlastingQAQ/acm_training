#include <stdio.h>

int main ()
{
	int n = 0;
	scanf("%d", &n);
	
	int first = 0;
	scanf("%d", &first);
	
	int max = first;
	int min = first;
	int num = 0;
	int cntmax = 1;
	int cntmin = 1;
	
	for (int cnt = 1; cnt < n; cnt++) {
		scanf("%d", &num);
		if (num > max) {
			max = num;
			cntmax = 1;
		}else if (num == max) {
			cntmax++;
		}
		if (num < min) {
			min = num;
			cntmin = 1;
		}else if (num == min) {
			cntmin++;
		}
	}
	
	printf("%d %d\n%d %d", min, cntmin, max, cntmax);
	
	return 0;
}
