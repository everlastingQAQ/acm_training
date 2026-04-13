#include <stdio.h>

int main ()
{	
    int result = 1;
    int cnt = 0;

	do {
		int num = 0;
		result = scanf("%d", &num);
		cnt++;
		if (num == 250) {
			break;
		}
	}while (result == 1);
	
	printf("%d", cnt);
	
	return 0;
	
}
