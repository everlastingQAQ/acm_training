#include <stdio.h>
int main() {
	char str1[101],str2[101];
	int i;
	gets(str1);
	// Please fill this blank
	for (i = 0; str1[i] != '\0'; i++) {
		str2[i] = str1[i]; 
	}
	str2[i] = '\0';
	
	puts(str2);
	return 0;
}
