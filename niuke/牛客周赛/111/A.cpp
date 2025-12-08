#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b, c;
	cin >> a >> b >> c;
	
	if (b - a == 1 && c - b == 1) {
		cout << "Yes";
	}else {
		cout << "No";
	}
	
	return 0;
}
