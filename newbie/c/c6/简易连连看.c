#include <stdio.h>

void printing (int n, char s[n][n])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", s[i][j]);
			if (j < n - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int N = 2 * n;
	char s[N][N];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &s[i][j]);
		}
	}
	
	int k;
	scanf("%d", &k);
	
	int a[k][4];
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	int cnt1 = 0;
	int cnt2 = 0;
	
	for (int i = 0; i < k; i++) {
		
		if (s[a[i][0] - 1][a[i][1] - 1] == s[a[i][2] - 1][a[i][3] - 1] && (s[a[i][0] - 1][a[i][1] - 1] != '*' && s[a[i][2] - 1][a[i][3] - 1] != '*')) {
			cnt1++;
			if (cnt1 == N * N / 2) {
				printf("Congratulations!");
				return 0;
			}
			s[a[i][0] - 1][a[i][1] - 1] = '*';
			s[a[i][2] - 1][a[i][3] - 1] = '*';
			printing(N, s);
			continue;
		}
		
		if (s[a[i][0] - 1][a[i][1] - 1] != s[a[i][2] - 1][a[i][3] - 1] || (s[a[i][0] - 1][a[i][1] - 1] == '*' && s[a[i][2] - 1][a[i][3] - 1] == '*')) {
			cnt2++;
			printf("Uh-oh\n");
			if (cnt2 == 3) {
				printf("Game Over");
				return 0;
			}
		}
		
	}
	
	return 0;
}
