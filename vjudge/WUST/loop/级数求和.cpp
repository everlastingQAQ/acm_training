#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int k;
	cin >> k;
	
	int n;
	double sum = 0;
	for (int i = 1; ; i++) {
		sum += 1.0 / i;
		if (sum > k) {
			n = i;
			break;
		}
	}	
	
	cout << n << endl;
	
	return 0;
	
}
