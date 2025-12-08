#include <stdio.h>

int main ()
{
	char s[1001];
	gets(s);
	
	int length_I = 1;
	
	for (int i = 1; s[i] != '\0'; i++) {
		
		int length_i = 1;
		
		for (int j = 1; s[i + j] == s[i - j] && i - j >= 0; j++) {	
			length_i += 2;
		}
		
		if (length_i > length_I) {
			length_I = length_i;
		}
		
	}
	
	int length_J = 0; 
	
	for (int i = 0; s[i] != '\0'; i++) {
		
		int length_j = 0;
		
		for (int j = 1; s[i + 1 - j] == s[i + j] && i + 1 - j >= 0; j++) {
			length_j += 2;
		}
		
		if (length_j > length_J) {
			length_J = length_j;
		} 
	}
	
	if (length_J > length_I) {
		printf("%d", length_J);
	}else {
		printf("%d", length_I);
	}
	
	return 0;
	
}
