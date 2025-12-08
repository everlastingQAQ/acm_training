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
	
	int minimum = a[0];
	int minimum_a = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < minimum) {
			minimum = a[i];
			minimum_a = i;
		}
	}
	
	int maximum = b[0];
	int maximum_b = 0;
	for (int i = 1; i < n; i++) {
		if (b[i] > maximum) {
			maximum = b[i];
			maximum_b = i;
		}
	}
	
	cout << minimum_a + 1 << ' ' << maximum_b + 1;
	
	return 0;
	
}
