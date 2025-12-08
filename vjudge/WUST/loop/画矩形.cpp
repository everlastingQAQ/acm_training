#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b, f;
	char c;
	cin >> a >> b >> c >> f;
	if (f != 0) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cout << c;
			}
			cout << endl;
		}
	}else {
		for (int i = 0; i < a; i++) {
			if (i == 0 || i == a - 1) {
				for (int j = 0; j < b; j++) {
					cout << c;
				}
				cout << endl;
			}else {
				cout << c;
				for (int k = 0; k < b - 2; k++) {
					cout << ' ';
				}
				cout << c << endl;
			}	
		}
	}
	return 0;
}
