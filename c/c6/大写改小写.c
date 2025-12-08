#include <stdio.h>

int main ()
{
	char ch;
	while (scanf("%c", &ch) != EOF && ch != '\n') {
		if (ch >= 'A' && ch <= 'Z') {
			ch += 32;
		}
		putchar(ch);
	}
	
	return 0;
	
}
