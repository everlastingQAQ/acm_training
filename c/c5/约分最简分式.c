#include <stdio.h>

int main ()
{
	int a, b;
	scanf("%d/%d", &a, &b);
	
	int i = 2;
	
	while (i <= a) {
		if (a % i == 0) {
			if (b % i == 0) {
				a /= i;
				b /= i;
			}else {
				i++;
			}
		}else {
			i++;
		}
	}
	
	if (a == b) {
		printf("1/1");
	}else {
		printf("%d/%d", a, b);
	}
	
	return 0;
	
}
