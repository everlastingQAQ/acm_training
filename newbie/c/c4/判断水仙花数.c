#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	
	int a, b, c;
	a = num / 100;
	b = num / 10 - a * 10;
	c = num - a * 100 - b * 10;
	
	int A = 1;
	int B = 1;
	int C = 1;
	
	int cnt = 0;
	
	
	do {
		A *= a;
		B *= b;
		C *= c;
		
		cnt++;
		
	}while (cnt != 3);
	
	int res;
	res = A + B + C;
	
	if (res == num) {
		printf("YES");
		
	}else {
		printf("NO");
	}
	
	return 0;
	
}
