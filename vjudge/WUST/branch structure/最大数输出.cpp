#include <bits/stdc++.h>
using namespace std;

int main ()
{
	long int n;
	long int max;
	cin >> n;
	max = n;
	for (int i = 0; i < 2; i++) {
		cin >> n;
		if (n > max) {
			max = n;
		}
	}
	cout << max;
	return 0;
}
