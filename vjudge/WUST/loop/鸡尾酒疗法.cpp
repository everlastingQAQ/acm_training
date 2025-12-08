#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a[n][2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> a[i][j];
		}
	}
	
	double t = 1.0 * a[0][1] / a[0][0];
	
	for (int i = 1; i < n; i++) {
		double m = 1.0 * a[i][1] / a[i][0];
		if (m - t > 0.05) {
			cout << "better" << endl;
		}else if (t - m > 0.05) {
			cout << "worse" << endl;
		}else {
			cout << "same" << endl;
		}
	}
	
	return 0;
	
}
