#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a[8][3] = {};
	int b[8] = {};
	for (int i = 1; i < 8; i++) {
		for (int j = 1; j < 3; j++) {
			cin >> a[i][j];
			b[i] += a[i][j];
		}
	}
	
	int maximum = b[1];
	int cnt = 1;
	for (int i = 2; i < 8; i++) {
		if (b[i] > maximum) {
			maximum = b[i];
			cnt = i;
		}
	}
	if (maximum > 8) {
		cout << cnt;
	}else {
		cout << 0;
	}
	return 0;
}
