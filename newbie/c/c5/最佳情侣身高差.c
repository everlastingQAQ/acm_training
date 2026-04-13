#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
    char x;
	double h;
	int cnt = 0;
	
	do {
	    scanf(" %c", &x);
		scanf("%lf", &h);
		if (x == 'M') {
			h /= 1.09;
		}else {
			h *= 1.09;
		}
		
		printf("%.2f\n", h);
		cnt++;
    } while (cnt < n);	
    
    return 0;
}
