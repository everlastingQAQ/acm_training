#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		sum += t;
	}
	
	double average = 1.0 * sum / n;
	
	cout << fixed << setprecision(2) << average << endl;
	
	return 0;
}
