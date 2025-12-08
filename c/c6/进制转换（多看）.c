#include <stdio.h>

int main ()
{
	char str[100];
	
	int num = 0;
	int i = 0;
	char c;
	
	while ((c = getchar()) != '#') {
		if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
			str[i++] = c;
			num *= 16;
			if (c >= '0' && c <= '9') {
                num += c - '0';
            }else if (c >= 'A' && c <= 'F') {
                num += c - 'A' + 10;
            }else if (c >= 'a' && c <= 'f') {
            	num += c - 'a' + 10;
			}
		}
	}
	
	str[i] = '\0';
	
	printf("String:%s\n", str);	
	printf("number=%d", str);
	
	return 0;
	
}
