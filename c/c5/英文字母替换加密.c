#include <stdio.h>

int main ()
{
	char c = '0';
	
	while (c != '\n') {
		scanf("%c", &c);
		if (c >= 65 && c <= 90) {
			c += 33;
			if (c > 'z') {
				c = 'a';
			}
		}else if (c >= 97 && c <= 122) {
			c -= 31;
			if (c > 'Z') {
				c = 'A';
			}
		}
		
		printf("%c", c);
	}
	
	return 0;
}
