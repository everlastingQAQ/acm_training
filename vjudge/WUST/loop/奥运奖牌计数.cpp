#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a[n][3];
	int gold = 0;
	int silver = 0;
	int bronze = 0;
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			sum += a[i][j];
			if (j == 0) {
				gold += a[i][j];
			}else if (j == 1) {
				silver += a[i][j];
			}else {
				bronze += a[i][j];
			}
		}
	}
	
	cout << gold << ' ' << silver << ' ' << bronze << ' ' << sum << endl;
	
	return 0;
}
