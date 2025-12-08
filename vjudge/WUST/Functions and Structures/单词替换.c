#include <stdio.h>
#include <string.h>

int main ()
{
	char s[201];
	char a[101];
	char b[101];
	
	fgets(s, 201, stdin);
	s[strcspn(s, "\n")] = '\0';
	fgets(a, 101, stdin);
	a[strcspn(a, "\n")] = '\0';
	fgets(b, 101, stdin);
	b[strcspn(b, "\n")] = '\0';
	
	int len_s = strlen(s);
	
	int i = 0;
	while (i < len_s) {
		char c[201] = {0};
		
		while (i < len_s && s[i] == ' ') {
			printf(" ");
			i++;
		}
		
		if (i >= len_s) {
			break;
		}
		
		int j = 0;
		while (i < len_s && s[i] != ' ') {
			if (j < 200) { 
				c[j++] = s[i++];
			} else {
				i++;
			}
		}
		
		if (strcmp(a, c) == 0) {
			printf("%s", b);
		}else {
			printf("%s", c);
		}
	}
	
	
	printf("\n");
	return 0;
	
}
