#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double x, a, y, b;
	cin >> x >> a >> y >> b;
	double res = (a * x - b * y) / (a - b);
	printf("%.2f", res);
	return 0;
}
