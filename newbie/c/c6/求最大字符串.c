#pragma GCC diagnostic ignored "-Wattribute-warning"
#include <stdio.h>
#include <string.h>

int main ()
{
	int n;
	scanf("%d", &n);
	getchar();
	
	char str[n][100];
	
	for (int i = 0; i < n; i++) {
		gets(str[i]);
	}
	
	int maxI = 0;
	
	for (int i = 1; i < n; i++) {
		if (strcmp(str[i], str[maxI]) > 0) {
			maxI = i;
		}
	}
	
	printf("%s", str[maxI]);
	
	return 0;
	
}
