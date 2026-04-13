#include <stdio.h>

int main()
{
	int scr;
	scanf("%d", &scr);
	
	int tag = scr;
	scr /= 10;
	
	switch ( scr ) {
		case 10:
		case 9:
			printf("score=%d,grade:A", tag);
			break;
			
		case 8:
			printf("score=%d,grade:B", tag);
			break;
			
		case 7:
			printf("score=%d,grade:C", tag);
			break;
			
		case 6:
			printf("score=%d,grade:D", tag);
			break;
			
	    default:
			printf("score=%d,grade:E", tag);
			break;
	}
	
	return 0;
}
