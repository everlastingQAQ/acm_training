#include <stdio.h>

int main ()
{
	int n[31];
	
	for (int i = 0; i < 31; i++) {
		scanf("%d", &n[i]);
	}
	
	int cnt[31][31] = {0};
	
	for (int i = 0; i < 31; i++) {
		int mask = 0;
		if (n[i] == 1) {
			n[i] = 0;
			mask = 1;
		}
		int k = 0;
		for (int j = 0; j < 31; j++) {
			if (n[j] == 0) {
				cnt[i][k]++;
			}else if (n[j] == 1) {
				k++;
			}
		}
		if (mask == 1) {
			n[i] = 1;
		}
	}		
	
	int maxI = 0;
	int maxJ = 0;
	
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			if (cnt[i][j] > cnt[maxI][maxJ]) {
				maxI = i;
				maxJ = j;
			}
		}
	}
	
	printf("%d", cnt[maxI][maxJ]);
	
	return 0;
}
