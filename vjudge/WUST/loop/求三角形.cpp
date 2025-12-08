#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%02d", a);
			a++;
		}
		printf("\n");
	}
	
	printf("\n");
	a = 1;
	int i = 2 * n - 2;
	int k = 0;
	while (1) {
		int t = i;
		while (1) { // int i = 2 * n - 2; ; i -= 2
			if (t <= 0) break;
			printf(" ");
			t--;
			
		}
		i -= 2;

		for (int j = 0; j <= k; j++) {
			printf("%02d", a);
			a++;
		}
		k++;
		if (k == n) goto f;
		printf("\n");
	}
	
	f:
	
	return 0;
}
