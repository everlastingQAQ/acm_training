#include <stdio.h>

int main()
{
	int ori, dis;
	
	scanf("%d %d", &ori, &dis);
	
	double final=ori*dis/10.00;
	
	printf("%.2f", final);
	
	return 0;
}
