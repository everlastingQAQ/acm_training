#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a[n + 1] = {1};
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; i * j <= n; j++) {
			a[i * j]++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (a[i] % 2 == 0) {
			cout << i << ' ';
		}
	}
	
	return 0;
}
