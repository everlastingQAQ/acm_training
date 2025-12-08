#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double m, h;
	cin >> m >> h;
	double BMI = m / h / h;
	if (BMI < 18.5) cout << "Underweight";
	if (BMI >= 18.5 && BMI < 24) cout << "Normal";
	if (BMI >= 24) cout << BMI << endl << "Overweight";
	return 0;
}
