#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, x;
	long long k;
	cin >> n >> k >> x;
	k %= x;
	
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int p = (x - k) % x;

	for (int i = p; i < x; i++) {
		cout << a[i] << ' ';
	}
	
	for (int i = 0; i < p; i++) {
		cout << a[i] << ' ';
	}
	
	for (int i = x; i < n; i++) {
		cout << a[i] << ' ';
	}
	
	return 0;
}
