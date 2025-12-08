#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b;
	vector <int> c;
	while (cin >> a >> b) {
		c.push_back(a + b);
	}
	
	for (auto sum : c) {
		cout << sum << endl;
	}
	
	return 0;
	
}
