#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int min, max;
	cin >> min;
	max = min;
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		if (t > max) {
			max = t;
		}else if (t < min) {
			min = t;
		}
	}
	cout << max - min << endl;
	return 0;
}
