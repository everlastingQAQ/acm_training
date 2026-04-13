#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int res;
	
	if (a > b) {
		if (b > c) {
			res = b;
		}else if (a > c) {
			res = c;
		}else {
			res = a;
		}
	}else if (a > c) {
		res = a;
	}else if (b > c) {
		res = c;
	}else {
		res = b;
	}
	
	printf("%d", res);
	
	return 0;
}
