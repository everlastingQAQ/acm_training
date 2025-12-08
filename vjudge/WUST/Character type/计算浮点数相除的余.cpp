#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double a, b;
	cin >> a >> b;
	
	int k = 0;
	double r;
	do {
		k++;
		r = a - b * k;
	}while (r >= 0);
	
	r = a - b * (k - 1);
	
	cout << r << endl;
	return 0;
}
