#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int m, n;
	cin >> m >> n;
	
	if (m % 2 == 0) {
		m++;
	}
	
	int sum = 0;
	for (int i = m; i <= n; i += 2) {
		sum += i;
	}
	
	cout << sum << endl;
	
	return 0;
}
