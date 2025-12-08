#pragma GCC diagnostic ignored "-Wattribute-warning"
#include <stdio.h>

int main ()
{
	char str[101];
	gets(str);
	
	char ch;
	scanf("%c", &ch);
	
	int j = 0;
	
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ch) {
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
	
	printf("%s", str);
	
	return 0;
}
