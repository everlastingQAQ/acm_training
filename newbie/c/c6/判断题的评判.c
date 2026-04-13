#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	int AC[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &AC[i]);
	}
	
	int WA[n];
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &WA[i]);
		if (WA[i] == AC[i]) {
			cnt++;
		}
	}
	
	double x;
	
	x = 1.0 * cnt / n;
	
	printf("%.2f%%", x * 100);
	
	return 0;
}
