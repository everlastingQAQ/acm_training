#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a[8];
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
	}
	
	int b[7] = {};
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int k = 0; k < 7; k++) {
			int t;
			cin >> t;
			for (int j = 0; j < 7; j++) {
				if (t == a[j]) {
					cnt++;
					break;
				}
			}
		}
		b[7 - cnt]++;
	}
	
	for (int i = 0; i < 7; i++) {
		cout << b[i] << ' ';
	}
	
	return 0;
}
