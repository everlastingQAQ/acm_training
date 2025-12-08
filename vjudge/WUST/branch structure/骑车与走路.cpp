#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double bike, walk, n;
	cin >> n;
	bike = 27 + 23 + n / 3.0;
	walk = n / 1.2;
	if (bike < walk) {
		cout << "Bike";
	}else if (bike == walk) {
		cout << "All";
	}else {
		cout << "Walk";
	}
	return 0;
}
