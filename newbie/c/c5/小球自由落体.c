#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int cnt = 0;
	double res = 0.0;
	double h = 100.0;
	int tag = 1;
	
	for (cnt = 0; cnt< n; cnt++) {
		if (tag == 1) {
			res += 100;
			tag = 0;
		}else {
			h /= 2;
		    res += h*2;
		    
		}
	}
		  
	printf("%lf %lf", res, h/2);

    return 0;

}
