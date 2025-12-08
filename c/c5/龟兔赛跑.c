#include <stdio.h>

int main ()
{
	int t;
	scanf("%d", &t);
	
	int st = 0;
    int sr = 0;
    int rest = 0;
    int mask = 0;
    
    for (int minute = 1; minute <= t; minute++) {
        st += 3;
        
        if (rest > 0) {
            rest--;
        } else {
            sr += 9;
            mask++;
            
        if (mask == 10) {
            if (sr > st) {
                rest = 30;
	            }
	            mask = 0;
	        }
	    }
	}
	
    if (sr > st) {
    	printf("^_^ %d", sr);
    } else if (sr < st) {
        printf("@_@ %d", st);
    } else {
        printf("-_- %d", st);
    }
	
	return 0;
}
