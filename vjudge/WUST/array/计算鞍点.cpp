#include <bits/stdc++.h>
using namespace std;
const int n = 5;

int main ()
{
	int a[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	bool FIND =  false;
	for (int i = 0; i < n; i++) {
		bool find_X = true;
		int maximum = a[i][0];
		int o = i;
		int p = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] > maximum) {
				maximum =  a[i][j];
				o = i;
				p = j;
			}
		}
		
		for (int k = 0; k < n; k++) {
			if (a[k][p] < maximum) {
				find_X = false;
				break;
			}
		}
		if (find_X == true) {
			FIND = true;
			cout << o + 1 << ' ' << p + 1 << ' ' << maximum << endl;
		}
	}
	
	if (FIND == false) {
		cout << "not found";
	}
	
	return 0;
}
