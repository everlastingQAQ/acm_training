#include <bits/stdc++.h>
using namespace std;

int main ()
{
	string s;
	cin >> s;
	
	bool o = true;
	for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			o = false;
			break;
		}
	}
	if (o == true) cout << "yes";
	if (o == false) cout << "no";
	
	return 0;
}
