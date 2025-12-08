#include <stdio.h>

int main ()
{
    int n;
	scanf("%d", &n);
	
	int j = 1;
    int sum = 0;
    
    for (int cnt = 1; cnt < n; cnt++) {
	    
		int a = 0;
	    int b = 0;
	    int mask = 0;
	    
		for (int i = 31; i >= 0; i--) {
	        if (j & (1 << i)) {
	            a++;
	            mask = 1;
	        } else if (mask == 1) {
	            b++;
	        }
	        
	    }
	    
	    if (a > b) {
        	sum++;
		}
		
		j++;
	}
    
    printf("%d", sum);
    
    return 0;
}
