#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int max = 0;
	int cnt = 1;
	int num = 0;
	
	scanf("%d", &max);
	
	for (cnt = 1; cnt < n; cnt++) {
		scanf("%d", &num);
		if (num > max) {
			max = num;
		}
	}
	
    printf("%d", max);
	
	return 0;
}
