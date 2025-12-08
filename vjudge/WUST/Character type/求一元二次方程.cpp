#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double a, b, c;
	cin >> a >> b >> c;
	
	double p = 1.0 * b * b - 4.0 * a * c;
	if (p < 0) {
		cout << "No answer!";
	}else if (p == 0) {
		double x = (-1.0) * b / 2.0 / a;
		cout << "x1=x2=" << fixed << setprecision(5) << x;
	}else {
		p = sqrt(p);
		double x1 = 1.0 * (p - b) / 2.0 / a;
		double x2 = 1.0 * ((-1) * p - b) / 2.0 / a;
		if (x2 < x1) {
			swap(x1,x2);
		}
		cout << "x1=" << fixed << setprecision(5) << x1 << ";x2=" << fixed << setprecision(5) << x2;
	}
	return 0;
}
