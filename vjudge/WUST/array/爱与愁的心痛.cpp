#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int minimum = 0;
	for (int i = 0; i < m; i++) {
		minimum += a[i];	
	}
	
	for (int i = 1; i + m <= n; i++) {
		int t = 0;
		int k = i;
		for (int j = 0; j < m; j++) {
			t += a[k];
			k++;
		}
		if (t < minimum) {
			minimum = t;
		}
	}
	
	cout << minimum;
	
	return 0;
}
