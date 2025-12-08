#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		double t;
		cin >> t;	
		sum += t;
	}
	double average = 1.0 * sum / n;
	cout << average << endl;
	return 0;
}
