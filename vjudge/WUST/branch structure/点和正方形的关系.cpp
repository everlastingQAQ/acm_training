#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int x, y;
	cin >> x >> y;
	if (abs(x) > 1 || abs(y) > 1) {
		cout << "no";
	}else cout << "yes";
	return 0;
}
