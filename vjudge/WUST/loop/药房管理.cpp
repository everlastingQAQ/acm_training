#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int m, n;
	cin >> m >> n;
	
	int remain = n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		m -= t;
		if (m < 0) {
			m += t;	
		}else {
			remain--;
		}
	}
	
	cout << remain << endl;
	
	return 0;
	
}
