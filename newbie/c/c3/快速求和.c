#include <stdio.h>

int main()
{
	int n;
	
	scanf("%d", &n);
	
	int tag;
	double s=0.0;
	
	for (tag=1; tag<=n; tag++){
		s+=1.0/(tag*(tag+1.0));
	}
	
	printf("%.5f", s);
	
	return 0;
}
