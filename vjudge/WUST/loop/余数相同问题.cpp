#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b, c;
	cin >> a >> b >> c;
	
	int x = 2;
	while (1) {
		if (a % x == b % x && a % x == c % x) {
			break;
		}
		x++;
	}
	
	cout << x << endl;
	
	return 0;
	
}
