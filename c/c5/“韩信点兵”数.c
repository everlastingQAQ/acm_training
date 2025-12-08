#include <stdio.h>

int main()
{
	int min, max;
	scanf("%d %d", &min, &max);
	
	int res = 0;
	int cnt = 0;
	int tag = 1;
	
	for (res = min; res <= max ; res++) {
		if (res % 3 == 2 && res % 5 == 3 && res % 7 == 4) {
					if ( tag == 1) {
						printf("%d", res);
						tag = 0;
						cnt++;
					}else {
					cnt++;
		            printf(" %d", res);
			}
		}
		
	}
	
	if (cnt == 0) {
		printf("total=0");
	}else {
		printf("\ntotal=%d", cnt);
    }
	
	return 0;
}
