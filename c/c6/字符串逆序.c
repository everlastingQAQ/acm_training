#include <stdio.h>
#include <string.h>

int main ()
{
	char a[81];
	
	fgets(a, sizeof(a), stdin);
	
	int length = strlen(a);
	
	int j = length - 1;
	int i = 0;
	
	while (i < j) {
		char b = a[i];
		a[i] = a[j];
		a[j] = b;
		i++;
		j--;
	}
	
	printf("%s", a);
	
	return 0;
	
}
