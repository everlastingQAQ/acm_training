#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int x, n;
	cin >> x >> n;
	bool a[8] = {0, 1, 1, 1, 1, 1, 0, 0};
	int rs = 0;
	while (n > 0) {
		if (a[x]) {
			rs += 250;
		}
		n--;
		x++;
		if (x == 8) {
			x = 1;
		}
	}
	cout << rs;
	return 0;
}
