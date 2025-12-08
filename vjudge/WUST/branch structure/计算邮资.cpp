#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a;
	char c;
	cin >> a >> c;
	int res = 0;
	if (a <= 1000) {
		res = 8;
	}else {
		if ((a - 1000) % 500 != 0) {
			res = 8 + ((a - 1000) / 500 + 1) * 4;  
		}else {
			res = 8 + (a - 1000) / 500 * 4;
		}
	}
	if (c == 'y') res += 5;
	cout << res;
	return 0;
}
