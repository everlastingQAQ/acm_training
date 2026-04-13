#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int num1, num2, num3;
	
	if (a > b) {
		if (a > c){
			num1 = a;
			if (b > c){
			    num2 = b, num3 = c;
		    }else {
			    num2 = c, num3 = b;
		        }
	        }else {
	        num1 = c, num2 = a, num3 = b;
			} 
		
	}else{
		if (b > c){
			num1 = b;
			if (a > c){
				num2 = a, num3 = c;
			}else {
				num2 = c, num3 = a;
			}
		}else{
			num1 = c, num2 = b, num3 = a;
		}
	}
	
	printf("a=%d,b=%d,c=%d", num3, num2, num1);
	
	return 0;
}
