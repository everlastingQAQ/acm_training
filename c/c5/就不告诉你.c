#include <stdio.h>

int main ()
{
	int a, b;
	scanf("%d %d", &a, &b);
	
	int plus = a * b;
	int t = plus;
	int cnt = 0;
	
	while (t > 0) {
		t /= 10;
		cnt++;	
	}
	
	int temp = plus;
	
	for (int n = 1; n <= cnt; n++) {
		int temp = plus;
		temp %= 10;
		plus /= 10;
		printf("%d", temp);
	}
	
    return 0;
    
}
