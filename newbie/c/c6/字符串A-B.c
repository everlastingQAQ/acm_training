#include <stdio.h>

int main ()
{
	char a[10001];
	gets(a);
	char b[10001];
	gets(b);
	
	int c[10001] = {0};
	
	int k = 0;
	
	for (int i = 0; a[i] != '\0'; i++) {
		for (int j = 0; b[j] != '\0'; j++) {
			if (b[j] == a[i] ) {
				c[k++] = i;
				break;
			}
		}
	}
	
	for (int i = 0; a[i] != '\0'; i++) {
		int mask = 1;
		for (int j = 0; j < k; j++) {
			if (i == c[j]) {
				mask = 0;
				break;
			}
		}
		if (mask == 1) {
			printf("%c", a[i]);
		}
	}
	
	return 0;
} 
