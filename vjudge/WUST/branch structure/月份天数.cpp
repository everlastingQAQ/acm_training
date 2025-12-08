#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int y, m;
	cin >> y >> m;
	int a[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
		cout << a[m];
	}else {
		a[2] = 28;
		cout << a[m];
	}
	return 0;
}
