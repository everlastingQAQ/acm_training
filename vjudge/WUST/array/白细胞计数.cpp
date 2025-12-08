#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	double a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int maximum = 0;
	int minimum = 0;
	double sum = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > a[maximum]) {
			maximum = i;
		}else if (a[i] < a[minimum]) {
			minimum = i;
		}
		sum += a[i];
	}
	
	sum -= a[minimum] + a[maximum];
	double average = 1.0 * sum / (n - 2);
	
	double difference = 0.0;
	
	for (int i = 0; i < n; i++) {
		if (i == minimum || i == maximum) {
			continue;
		}
		double diff = fabs(a[i] - average);
		if (diff > difference) {
			difference = diff;
		}
	}
	
	cout << fixed << setprecision(2) << average << ' ' << fixed << setprecision(2) << difference;
	
	return 0;
	
}
