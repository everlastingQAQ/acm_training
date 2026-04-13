#include <stdio.h>

int main ()
{
	char str1[101];
	gets(str1);
	
	char str2[101];
	gets(str2);
	
	int i = 0;
	
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
		i++;
	}
	
	printf("%d", str1[i] - str2[i]);
	
	return 0;
}
