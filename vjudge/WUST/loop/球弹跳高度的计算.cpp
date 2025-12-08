#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int h;
	cin >> h;
	
	double sum = h;
	double height = h;
	for (int i = 1; i < 10; i++) {
		height /= 2;
		sum += height * 2;
	}
	cout << sum << endl << height / 2.0 << endl;
	return 0;
}
