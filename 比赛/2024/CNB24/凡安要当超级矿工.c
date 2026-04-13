#include <stdio.h>

int main ()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int s[n][m];
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &s[i][j]);
			if (s[i][j] == 6) {
				cnt++;
			}
		}
	}
	
	if (cnt % 2 == 0) {
		printf("Super Miner is Era2333");
	}else {
		printf("Super Miner Fan_an tql");
	}
	
	return 0;
	
}
