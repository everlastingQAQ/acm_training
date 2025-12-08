#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b, n;
	cin >> a >> b >> n;
	
	for (int i = 0; i < n; i++) {
		a %= b;
		a *= 10;
	}
	
	a /= b;
	
	cout << a << endl;
	
	return 0;
}
