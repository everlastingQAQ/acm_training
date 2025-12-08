#include <stdio.h>

int main  () 
{
    int n;
    scanf("%d", &n);
    
    int mask = 1;
    
    char name [50] [4];
    int a [50] ,b [50];
    
    for (int i = 0; i < n; i++) {
        scanf("%3s %d %d", name [i], &a [i], &b [i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (a [i] < 15 || a [i] > 20 || b [i] < 50 || b [i] > 70) {
        	if (mask == 1) {
        		printf("%s", name [i]);
        		mask = 0;
			}else {
				printf("\n%s", name [i]);
			}
        }
    }
    
    return 0;
    
}
