#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
	double a[3][2];
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%lf", &a[i][j]);
		}
	}
	
	double dis1, dis2, dis3;
	
	dis1 = sqrt(pow(fabs(a[0][0] - a[1][0]), 2) + pow(fabs(a[0][1] - a[1][1]), 2));
	dis2 = sqrt(pow(fabs(a[0][0] - a[2][0]), 2) + pow(fabs(a[0][1] - a[2][1]), 2));
	dis3 = sqrt(pow(fabs(a[1][0] - a[2][0]), 2) + pow(fabs(a[1][1] - a[2][1]), 2));
	
	double p = dis1 + dis2 + dis3;

	printf("%.2f", p);
	
	return 0;
}
