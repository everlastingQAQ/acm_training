#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b;
	cin >> a >> b;
	double r = 1.0 / (1.0 / a + 1.0 / b);
	cout << fixed << setprecision(2) << r;
	return 0; 
}
