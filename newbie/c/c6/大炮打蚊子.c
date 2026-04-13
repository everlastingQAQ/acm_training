#include <stdio.h>

int main ()
{
	int m, n;
	scanf("%d %d", &m, &n);
	
	char s[m][n];
	int b[m][n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &s[i][j]);
			b[i][j] = 0;
		}
	}
	
	int k;
	scanf("%d", &k);
	
	int cnt[k];
	
	for (int i = 0; i < k; i++) {
		int o, p;
		scanf("%d %d", &o, &p);
		b[o][p] += 2;
		if (o + 1 < m) b[o + 1][p] += 1;
		if (o - 1 >= 0) b[o - 1][p] += 1;
		if (p + 1 < n) b[o][p + 1] += 1;
		if (p - 1 >= 0) b[o][p - 1] += 1;
		
		cnt[i] = 0;
		
		if (b[o][p] >= 2 && s[o][p] == '#') {
			cnt[i]++;
			s[o][p] = '0';
		}
		
		if (o + 1 < m && b[o + 1][p] >= 2 && s[o + 1][p] == '#') {
			cnt[i]++;
			s[o + 1][p] = '0';
		}
		if (o - 1 >= 0 && b[o - 1][p] >= 2 && s[o - 1][p] == '#') {
			cnt[i]++;
			s[o - 1][p] = '0';
		}
		
		if (p + 1 < n && b[o][p + 1] >= 2 && s[o][p + 1] == '#') {
			cnt[i]++;
			s[o][p + 1] = '0';
		}
		
		if (p - 1 >= 0 && b[o][p - 1] >= 2 && s[o][p - 1] == '#') {
			cnt[i]++;
			s[o][p - 1] = '0';
		}
		
	}
	
	for (int i = 0; i < k; i++) {
		printf("%d", cnt[i]);
		if (i < k - 1) {
			printf("\n");
		}
	}
	
	return 0;
	
}
