#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double a;
	cin >> a;
	int day = 1;
	while (a > 1) {
		a = floor(a / 2.0);
		day++;
	}
	cout << day << endl;
	return 0;
}
