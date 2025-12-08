#include <bits/stdc++.h>
using namespace std;

int main ()
{
	string s;
	cin >> s;
	
	string sf;
	for (char c : s) {
		sf += toupper(c);
	}
	
	cout << sf;
	
	return 0;
}
