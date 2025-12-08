#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int max;
	cin >> max;
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		if (t > max) {
			max = t;
		}
	}
	
	cout << max << endl;
	
	return 0;
	
}
