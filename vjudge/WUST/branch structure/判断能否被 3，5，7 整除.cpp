#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	bool i = 0;
	if (n % 3 == 0) {
		cout << 3 << ' ';
		i = 1;
	}
	if (n % 5 == 0) {
		cout << 5 << ' ';
		i = 1;
	}
	if (n % 7 == 0) {
		cout << 7;
		i = 1;
	}
	if (i == 0) {
		cout << 'n';
	}
	return 0;
}
