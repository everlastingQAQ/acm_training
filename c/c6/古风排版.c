#include <stdio.h>

int ceiling (double num)
{
	int i = (int)num;
	if (num > i) {
		return i + 1;
	}
	return i;
}


int main ()
{
	int n;
	scanf("%d", &n);
	getchar();
	
	char s[1001];
	gets(s);
	
	int len = 0;
	
	while (s[len] != '\0') {
		len++;
	}
	s[len] = '\0';
	
	int column = ceiling((double)len / n);
	
	char c[n][column];
	
	int k = 0;
	
	for (int j = column - 1; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			if (k < len) {
				c[i][j] = s[k++];
			} else {
				c[i][j] = ' ';
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < column; j++) {
			printf("%c", c[i][j]);
		}
		printf("\n");
	}
	
	return 0;
	
}
