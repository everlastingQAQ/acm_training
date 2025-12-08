#include <bits/stdc++.h>
using namespace std;

int a[31];

void Fibonacci()
{
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i < 31; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
}

int main ()
{
	Fibonacci();
	int n;
	cin >> n;
	
	int b[n];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	for (int i = 0; i < n; i++) {
		cout << a[b[i]] << endl;
	}
	
	return 0;
}
