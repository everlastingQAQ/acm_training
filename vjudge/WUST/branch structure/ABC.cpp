#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	for (int i = 0; i < 3; i++) {
		char d;
		cin >> d;
		if (d == 'A') cout << a << " ";
		if (d == 'B') cout << b << " ";
		if (d == 'C') cout << c << " ";
	}
	return 0;
}
