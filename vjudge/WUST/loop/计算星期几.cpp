#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b;
	cin >> a >> b;
	
	int x = 1;
	for (int i = 0; i < b; i++) {
		x *= a;
		x %= 7;
	}
	
	if (x == 0) cout << "Sunday";
	if (x == 1) cout << "Monday";
	if (x == 2) cout << "Tuesday";
	if (x == 3) cout << "Wednesday";
	if (x == 4) cout << "Thursday";
	if (x == 5) cout << "Friday";
	if (x == 6) cout << "Saturday";
	
	return 0;
	
}
