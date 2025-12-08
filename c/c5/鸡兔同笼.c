#include <stdio.h>

int main()
{
	int h, f;
	scanf("%d %d", &h, &f);
	
	int c = 0;
	int r = 0;
	int res = 0;
	
    for (r = 0; r<= h; r++) {
    	c = h - r;
    	if (4*r + 2* c == f) {
    		res = 1;
    		break;
		}
	}
    
	if (res == 1) {
		printf ("%d %d", c, r);
	}else {
		printf("Error");
	}
	
	return 0;
	
}
