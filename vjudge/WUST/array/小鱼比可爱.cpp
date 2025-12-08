#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int b[n] = {};
	for (int i = 1; i < n; i++) {
		int cnt = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] < a[i]) {
				cnt++;
			}
			b[i] = cnt;
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
	
	return 0;
}
