#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a[102];
	int n;
	
	for (int i = 0; ; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			n = i;
			break;
		}
	}
	
	for (int i = n - 1; i >= 0; i--) {
		cout << a[i] << ' ';
	}
	
	return 0;
	
}
