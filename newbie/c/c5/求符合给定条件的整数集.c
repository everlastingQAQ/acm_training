#include <stdio.h>

int main ()
{
	char a;
	scanf("%c", &a);
	
	char b = a + 1;
	char c = a + 2;
	char d = a + 3;
	
	if (a == '0') {
		int tag = 0;
		if (tag == 0) {
			printf("%c%c%c", b, a, c);
			tag = 1;
		}
		
		printf(" %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n", b, a, d, b, c, a, b, c, d, b, d, a, b, d, c);
		
		tag = 0;
		if (tag == 0) {
			printf("%c%c%c", c, a, b);
			tag = 1;
		}
		printf(" %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n", c, a, d, c, b, a, c, b, d, c, d, a, c, d, b);
		
		tag = 0;
		if (tag == 0) {
			printf("%c%c%c", d, a, b);
			tag = 1;
		}
		printf(" %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c", d, a, c, d, b, a, d, b, c, d, c, a, d, c, b);
		}else {
    int tag = 0;
	if (tag == 0) {
		printf("%c%c%c", a, b, c);
		tag = 1;
	} 
	
	printf(" %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n", a, b, d, a, c, b, a, c, d, a, d, b, a, d, c);
	
	tag = 0;
	if (tag == 0) {
		printf("%c%c%c", b, a, c);
		tag = 1;
	}
	
	printf(" %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n", b, a, d, b, c, a, b, c, d, b, d, a, b, d, c);
	
	tag = 0;
	if (tag == 0) {
		printf("%c%c%c", c, a, b);
		tag = 1;
	}
	printf(" %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n", c, a, d, c, b, a, c, b, d, c, d, a, c, d, b);
	
	tag = 0;
	if (tag == 0) {
		printf("%c%c%c", d, a, b);
		tag = 1;
	}
	printf(" %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c", d, a, c, d, b, a, d, b, c, d, c, a, d, c, b);
}
	return 0;
}
