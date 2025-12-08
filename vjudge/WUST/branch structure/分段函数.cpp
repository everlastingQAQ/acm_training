#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double x;
	cin >> x;
	double y;
	if (x >= 0 && x < 5) y = 2.5 - x;
	if (x >= 5 && x < 10) y = 2 - 1.5 * (x - 3) * (x - 3);
	if (x >= 10 && x < 20) y = x / 2.0 - 1.5;
	printf("%.3f", y);
	return 0;
}
