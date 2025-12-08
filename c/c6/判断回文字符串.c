#include <stdio.h>

int main ()
{
	char str[81] = {'\0'};
	gets(str);
	
	int cnt = 0;
	while (str[cnt] != '\0') {
		cnt++;
	}
	
	int mask = 1;
	for (int i = 0; i < cnt / 2 && str[i] != '\0' && str[cnt - 1 - i] != '\0'; i++) {
		if (str[i] != str[cnt - 1 - i]) {
			mask = 0;
			break;
		}
	}
	
	if (mask == 1) {
		printf("\nYes");
	}else {
		printf("\nNo");
	}
	
	return 0;
	
} 
