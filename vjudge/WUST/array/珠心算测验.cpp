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
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[i] == a[j] + a[k]) {
					cnt++;
					goto f;
				}
			}
		}
		f:;
	}
	
	cout << cnt;
	
	return 0;
}
