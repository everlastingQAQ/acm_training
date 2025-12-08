#include <stdio.h>

int main ()
{
	int m, n;
	scanf("%d %d", &m, &n);
	
	int i = m;
	int tag = 1;
	
	while (i <= n) {
		
		int j = 1;
		int k = i;
		
		int mask = 0;
		
		while (k > 0) {
			int num = k % 10;
			if (num == 5) {
				mask = 1;
				break;
			}else {
				k /= 10;
			}
		}
		
		if (i % 3 == 0 && mask == 1) {
			if (tag == 1) {
				printf("%d", i);
				tag = 0;
			}else {
				printf(" %d", i);
			}
		}
		
		i++;
		
	}
	
	if (tag == 1) {
		printf("No exist");
	}
	
	return 0;
	
}
