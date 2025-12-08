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
	
	int b[n];
	int k = 0;
	for (int i = 0; i < n; i++) {
		bool appeared = false;
		for (int j = 0; j < n && j != i; j++) {
			if (a[i] == a[j]) {
				appeared = true;
				break;
			}
		}
		if (appeared == false) {
			b[k] = a[i];
			k++;
		}
	}
	
	for (int i = 0; i < k; i++) {
		cout << b[i] << ' ';
	}
	
	return 0;
}
