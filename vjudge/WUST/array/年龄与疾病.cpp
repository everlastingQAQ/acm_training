#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p >= 0 && p <= 18) a++;
		if (p >= 19 && p <= 35) b++;
		if (p >= 36 && p <= 60) c++;
		if (p >= 61) d++;
	}
	
	double A = 100.0 * a / n;
	double B = 100.0 * b / n;
	double C = 100.0 * c / n;
	double D = 100.0 * d / n;
	
	cout << fixed << setprecision(2) << A << '%' << endl;
	cout << fixed << setprecision(2) << B << '%' << endl;
	cout << fixed << setprecision(2) << C << '%' << endl;
	cout << fixed << setprecision(2) << D << '%' << endl;
	
	return 0;
}
