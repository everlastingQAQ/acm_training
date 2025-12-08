#include <bits/stdc++.h>
using namespace std;

int main ()
{
	vector <int> v;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		v.push_back(a + b);
	}
	
	for (int sums : v) {
		cout << sums << endl;
	}
	
	return 0;
	
}
