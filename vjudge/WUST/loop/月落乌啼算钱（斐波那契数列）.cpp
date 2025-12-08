#include <bits/stdc++.h>
using namespace std;

int maxn = 49;
long long a[49];

void Fibonacci()
{
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i <= maxn; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
}

int main ()
{
	Fibonacci();
	int n;
	cin >> n;
	
	cout << a[n] << ".00";
	
	return 0;
}
