#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	int min = 1000;
	int m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (min > m) min = m;
	} 
	cout << min;
	return 0;
}
