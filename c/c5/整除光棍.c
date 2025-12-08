#include<stdio.h>

int main()
{	    
	int x;
	scanf("%d", &x);		
	int count = 1;   
	int a = 1;	    

	while (a < x) {			
		a = a * 10 + 1;		
		count++;
	}
	printf("%d", a / x);
		
	int t = a % x;  
	
	while (t != 0) {			//利用循环将商从高到低位依次输出，直到余数为0。
		t = t * 10 + 1;		
		printf("%d", t / x);
		count++;
		t %= x;
	}
	printf(" %d", count);

	return 0;
}
