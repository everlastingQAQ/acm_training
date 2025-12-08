#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int x = 100;
	int k = 1;
	for (int i = 0; i < 100; i++) {
		int sum;
		k = 1;
		do {
			sum = (7 * x + 21 * k) * 52;
			if (sum == n) {
				goto f;
			}
			k++;
		}while (sum < n);
		x--;
	}
	f:
	cout << x << endl << k << endl;
	
	return 0;
}
