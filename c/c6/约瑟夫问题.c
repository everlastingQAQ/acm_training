#include <stdio.h>

int main()
{
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	
	int num[n + 1];
	num[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		num[i] = i;
	}
	
	int i = s;
	int t = n;
	
	while (t > 0) {
		int cnt = 0;
		while (cnt < m) {
			if (num[i] != 0) {
				cnt++;
			}
			
			if (cnt < m) {
				i++;
				if (i > n) {
					i = 1;
				}
			}
		}
		printf("%3d", num[i]);
		num[i] = 0;
		t--;
		
		do {
			i++;
			if (i > n) {
				i = 1;
			}
		}while (num[i] == 0 && t > 0);
		
	}
	
	return 0;
	
}
