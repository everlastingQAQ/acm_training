#include <stdio.h>

int main ()
{
	int num[10];
	
	int n = 0;
	int mask = 0;
	
	for (int i = 0; i < 10; i++) {
		scanf("%d", &num[i]);
		if (num[0] != 0) {
			mask = 1;
		}
		n += num[i];
	}

	int s[n];
	int k = 0;
	int j = 0;
	
	for (int i = 0; i < 10; i++) {
		for (; j < n; j++) {
			if (num[i] > 0) {
				s[j] = k;
				num[i]--;
			}else break;
		}
		k++;
	}
	
	if (mask == 1) {
		for (int i = 0; i < n; i++) {
			if (s[i] != 0) {
				s[0] = s[i];
				s[i] = 0;
				break;
			}
		} 
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d", s[i]);
	}
	
	return 0;	
} 
