#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int s[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	
	int max = s[0] + s[1] + s[2] + s[3];
	int p = 0;
	
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			if (i + j >= n) {
				sum += s[i + j - n];
			}else {
				sum += s[i + j];
			}
		}
		if (sum > max) {
			max = sum;
			p = i;
		}
	}
	
	printf("%d %d", max, p + 1);
	
	return 0;
}
