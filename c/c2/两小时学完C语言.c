#include <stdio.h>

int main()
{
	int n, k ,m;
	
	scanf("%d %d %d", &n, &k, &m);
	
	int remain=n-k*m;
	
	printf("%d", remain);
	
	return 0;
}
