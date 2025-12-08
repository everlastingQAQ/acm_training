#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int i, j;
	cin >> i >> j;
	
	for (int k = 1; k <= n; k++) {
		cout << '(' << i << ',' << k << ") ";
	}
	cout << endl;
	
	for (int k = 1; k <= n; k++) {
		cout << '(' << k << ',' << j << ") ";
	}
	cout << endl;
	
	for (int k = 1; k <= n; k++) {
		for (int l = 1; l <= n; l++) {
			if (i - j == k - l) {
				cout << '(' << k << ',' << l << ") ";
			}
		}
	}
	cout << endl;
	
	for (int k = n; k > 0; k--) {
		for (int l = 1; l <= n; l++) {
			if (i + j == l + k) {
				cout << '(' << k << ',' << l << ") ";
			}
		}
	}
	cout << endl;
	
	return 0;
}
