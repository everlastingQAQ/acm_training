#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	double time = 0;
	for (int i = 0; i < n; i++) {
		double x, y;
		int sum;
		cin >> x >> y >> sum;
		double l = sqrt(x * x + y * y);
		time += 2.0 * l / 50 + sum * 1.5;
	}
	
	cout << int(ceil(time)) << endl;
	
	return 0;
	
}
