#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int i = (n - 1) / 2;
	int j = 1;
	int k = -1;
	
	int I = i;
	int J = j;
	int K = k;
	
	int tag = 1;
	
	while (I >= 0) {
		
		i = I;
		j = 2;
		k = K;
		
		int mask = 1;
		
		while (i > 0) {
			printf(" ");
			i--;
		}
		
		while (j > 0) {
			if (mask == 1) {
				if (tag == 1) {
					printf("*\n");
					break;
				}else {
					printf("*");
					mask = 0;
					
					while (k > 0) {
						printf(" ");
						k--;
					}
				}
				
			}else {
				printf("*\n");
			}
			
			j--;
				
		}
		
		tag = 0;
		
		I--;
		K += 2;
		
	}
	
	int h = 1;
	int b = 2;
	int m = n - 4;  
	
	int H = h;
	int B = b;
	int M = m;
	
	while (m >= 0) {
		
		h = H;
		b = 2;
		m = M;
		
		tag = 1;
		
		while (h > 0) {
			printf(" ");
			h--;
		}
		
		while (b > 0) {
			if (H == (n - 1) / 2) {
				printf("*");
				break;
			} 
			if (tag == 1) {
				printf("*");
				tag = 0;
				while (m > 0) {
					printf(" ");
					m--;	
				}
				
			}else {
				printf("*\n");
				break;
			}
		}
		
		H++;
		M -= 2;
		 
	}
	
	
	return 0;
}
