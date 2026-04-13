#include <stdio.h>
#include <stdlib.h>

int main ()
{
	for (int i = 0; i < 4; i++) {
		char s[8];
		scanf("%8s", s);
		
		long a = strtol(s, NULL, 2);
		
		printf("%ld", a);
		
		if (i < 3) {
			printf(".");
		}
	}
	
	return 0;
}
