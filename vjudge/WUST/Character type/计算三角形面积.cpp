#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double a, b, c;
	a = sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
	b = sqrt(abs(x1 - x3) * abs(x1 - x3) + abs(y1 - y3) * abs(y1 - y3));
	c = sqrt(abs(x3 - x2) * abs(x3 - x2) + abs(y3 - y2) * abs(y3 - y2));
	double p = (a + b + c) / 2.0;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << fixed << setprecision(2) << s << endl;
	return 0;
}
