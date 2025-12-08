#include <bits/stdc++.h>
using namespace std;

int main ()
{
	string s;
	getline(cin, s);
	
	int sum = 0;
	for (char c : s) {
		if (c >= '0' && c <='9') {
			sum++;
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
