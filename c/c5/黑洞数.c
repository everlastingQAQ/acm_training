#include <stdio.h>

int main ()
{
	int num = 0;
	scanf("%d", &num);
	
	int x = num;
	int temp = 0;
	int X = 0;
	int cnt = 1;
	
	do {
		int c = 0;
		int b = 0;
		int a = 0;
		
		c = x / 100;
		b = x / 10 - c * 10;
		a = x - c * 100 - b * 10;
		
		if (a > b) {
			if (b > c) {
				temp = a * 100 + b * 10 + c;
				x = c * 100 + b * 10 + a;
			}else if (a > c) { 
				temp = a * 100 + c * 10 + b;
				x = b * 100 + c * 10 + a;
			}else {
				temp = c * 100 + a * 10 + b;
				x = b * 100 + a * 10 + c;
			}
		}else if (a > c) {
			temp = b * 100 + a * 10 + c;
			x = c * 100 + a * 10 + b;
		}else if (b > c) {
			temp = b * 100 + c * 10 + a;
			x = a * 100 + c * 10 + b;
		}else {
			temp = c * 100 + b * 10 + a;
			x = a * 100 + b * 10 + c;
		}
	  
	    int mask = temp - x;
	    if (mask == 495) {
	    	printf("%d: %d - %d = %d", cnt, temp, x, mask);
		}else {
	        printf("%d: %d - %d = %d\n", cnt, temp, x, mask);
 		}
		X = x;
		x = mask;
		cnt++;
		
	}while (temp - X != 495);
	
	return 0;
}
