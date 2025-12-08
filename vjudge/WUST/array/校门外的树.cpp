#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int l, m;
	cin >> l >> m;
	
	bool a[l + 1];
	memset(a, true, sizeof(a));
	for (int i = 0; i < m; i++) {
		int o, p;
		cin >> o >> p;
		fill(a + o, a + p + 1, false);
	}
	int sum = 0;
	for (bool o : a) {
		if (o == true) {
			sum++;
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
