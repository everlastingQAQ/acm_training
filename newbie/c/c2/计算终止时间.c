#include <stdio.h>
#include <stdlib.h>

int main () 
{
    char str[4];
    double num;
    int a;
    
    scanf("%s %d", &str, &a);
    
    num = atof(str);
    
    int NUM = num;
    
    int min = NUM % 100;
    int hour = NUM / 100;
    
    int res = a + min;
    
    if (res >= 60) {
    	int temp = res / 60;
    	hour += temp;
    	res -= temp * 60;
	}else if (res < 0) {
		res = -res;
		int temp = res / 60;
		hour -= temp + 1;
		res -= temp * 60;
		res = 60 - res;
	}
	
	if (res >= 60) {
    	int temp = res / 60;
    	hour += temp;
    	res -= temp * 60;
}

	printf("%d%02d", hour, res);

    return 0;
}
