#include <stdio.h>

int main ()
{
	char c;
	int num[10] = {0};
	
	while (c != '!'){
		scanf("%c", &c);
		if (c >= '0' && c <= '9') {
			num[c - '0']++;
		}
	}
	
	for (int i = 0; i < 10; i++) {
		if (i == 9) {
			printf("The character %d appears %d times", i, num[i]);
		}else {
			printf("The character %d appears %d times\n", i, num[i]);
		}
	}
	
	return 0;
	
}
