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
	
	int maximum = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > maximum) maximum = a[i];
	}
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < maximum) sum += a[i];
	}
	
	cout << sum;
	
	return 0;
}
