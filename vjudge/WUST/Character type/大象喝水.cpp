#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int h, r;
	cin >> h >> r;
	double v = 3.14 * r * r * h; 
	double cnt = 1000.0 * 20 / v;
	cout << ceil(cnt);
	return 0;
}
