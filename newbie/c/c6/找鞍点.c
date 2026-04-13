#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int s[n][n];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &s[i][j]);
		}
	}

	int I = 0;
	
	
	while (I < n) {
		
		int jmax = 0;
		
		int i = 0;
		int j = 1;
		
		while (j < n) {
			if (s[I][j] > s[I][jmax]) {
				jmax = j;
			}
			j++;
		}
		
		int imin = 1;
		
		while (i < n) {
			if (s[i][jmax] < s[I][jmax]) {
				imin = 0;
				break;
			}
			i++;
		}
		
		if (imin == 1) {
			printf("%d %d", I, jmax);
			return 0;
		}
		
		I++;
	}
	
	printf("NONE");
	
	return 0;
	
}
