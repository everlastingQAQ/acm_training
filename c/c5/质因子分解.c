#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	printf("%d=", n);
	
	int t = n;
	
	for (int i = 2; i <= t;) {
		if (t % i != 0) {
			i++;
		}else if (t % i == 0 && t != i) {
			printf("%d*", i);
			t /= i;
		}else if (t % i == 0 && t == i) {
			printf("%d", i);
			break;
		}
	} 
		
	return 0;
}
