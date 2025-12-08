#include <stdio.h>

int main () 
{
	char str1[101],str2[101];
	int i,j;
	gets(str1);
	// Please fill this blank
	int l = 0;
	while (str1[l] != '\0') {
		l++;
	}
	for (i = 0, j = l - 1; j >= 0; i++, j--) {
		str2[i] = str1[j];
	}
	
	str2[l] = '\0';
	
	puts(str2);
	return 0;
}
