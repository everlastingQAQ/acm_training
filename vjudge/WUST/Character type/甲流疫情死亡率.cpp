#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b;
	cin >> a >> b;
	
	double res = 100.0 * b / a;
	
	cout << fixed << setprecision(3) << res << '%' << endl; 
	
	return 0;
}
