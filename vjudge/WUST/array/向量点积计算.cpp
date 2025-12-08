#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i] * b[i];
	}
	
	cout << res;
	
	return 0;
}
