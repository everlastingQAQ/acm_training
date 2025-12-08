#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a[11] = {0};
	int rs = 0;
	for (int i = 1; i < 11; i++) {
		if (i == 2 || i == 5 || i == 10) {
			char c;
			cin >> c;
		}
		char b;
		cin >> b;
		if (b == 'X') {
			a[i] = 10;
			break;
		}
		a[i] = b - '0';
		if (i < 10) {
			rs += a[i] * i;
		}
	}
	rs %= 11;
	if (a[10] == rs) {
		cout << "Right";
	}else {
		if (rs != 10) {
			printf("%d-%d%d%d-%d%d%d%d%d-%d", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], rs);
		}else {
			printf("%d-%d%d%d-%d%d%d%d%d-X", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
		}
		
	}
	return 0;
	
}
