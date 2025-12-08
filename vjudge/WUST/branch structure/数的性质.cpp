#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int x;
	cin >> x;
	bool a = 0;
	bool b = 0;
	if (x % 2 == 0) a = 1;
	if (x > 4 && x <= 12) b = 1;
	if (a && b) {
		cout << 1 << " ";
	}else {
		cout << 0 << " ";
	}
	if (!a && !b) {
		cout << 0 << " ";
	}else {
		cout << 1 << " ";
	}
	if (!a && b || a && !b) {
		cout << 1 << " ";
	}else {
		cout << 0 << " ";
	}
	if (!a && !b) {
		cout << 1;
	}else {
		cout << 0;
	}
	return 0;
}
