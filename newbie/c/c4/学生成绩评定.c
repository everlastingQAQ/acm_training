#include <stdio.h>

int main()
{
	int scr;
	scanf("%d", &scr);
	
	if (scr > 85) {
		printf("very good");
	}else if (scr <= 85 && scr >= 60) {
		printf("good");
	}else {
		printf("no good");
	}
	
	return 0;
	
}
