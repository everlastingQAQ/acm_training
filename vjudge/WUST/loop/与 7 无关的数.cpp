#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		bool mask = 1;
		if (i % 7 == 0) {
			mask = 0;
			continue;
		}
		int t = i;
		while (t > 0) {
			int m = t % 10;
			if (m == 7) {
				mask = 0;
				break;
			}
			t /= 10;
		}
		if (mask) {
			sum += i * i;
		}
	}
	
	cout << sum << endl;
	
	return 0;
	
}
