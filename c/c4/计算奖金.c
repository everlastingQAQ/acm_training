#include <stdio.h>

int main()
{
	double p;
	scanf("%lf", &p);
	
	double bonus;
	
	if (p <= 100000) {
		bonus = p * 0.10;

	}else if (p > 100000 && p <= 200000) {
		bonus = 10000 + (p - 100000) * 0.075;

	}else if (p > 200000 && p <= 400000) {
		bonus = 17500 + (p - 200000) * 0.05;

	}else if (p > 400000 && p <= 600000) {
		bonus = 27500 + (p - 400000) * 0.03;

	}else if (p > 600000 && p <= 1000000) {
		bonus = 33500 + (p - 600000) * 0.015; 

	}else if (p > 1000000) {
		bonus = 39500 + (p - 1000000) * 0.01; 
	
	}//¶ñÐÄ 
	
	printf("%.2f", bonus);
	
	return 0;
}
