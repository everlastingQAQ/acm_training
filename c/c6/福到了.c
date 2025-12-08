#include <stdio.h>

int main ()
{
	char ch;
	scanf("%c", &ch);
	
	int n;
	scanf("%d", &n);
	
	char s[n][n];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c = getchar();
			while (c == '\n') {
				c = getchar();
			}
			s[i][j] = (char)c;
		}
	}
	
	int mask = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] != s[n - 1 - i][n - 1 - j]) {
				mask = 0;
				goto f;
			}
		}
	}
	
	f:
	
	if (mask == 1) {
		printf("bu yong dao le\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char t = s[i][j];
			s[i][j] = s[n - 1 - i][n - 1 - j];
			s[n - 1 - i][n - 1 - j] = t;
			if (i == (n - 1) / 2 && j == n - 1) {
				goto final;
			}
		}
	}
	
	final:
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] != ' ') {
				s[i][j] = ch;
			}
			printf("%c", s[i][j]);
		}
		if (i < n - 1) {
			printf("\n");
		}
	}
	
	return 0;
	
}
