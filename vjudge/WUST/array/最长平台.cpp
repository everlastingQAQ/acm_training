#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	int a[n] = {};
	vector <int> s;
	cin >> a[0];
	int length = 0;
	
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		if (a[i] == a[i - 1]) {
			length++;
		}else {
			length++;
			s.push_back(length);
			length = 0;
		}
	}
	if (length == 0) {
		s.push_back(1);
	}else {
		s.push_back(length);
	}
	
	int m = s[0];
	for (int p : s) {
		if (p > m) {
			m = p;
		}
	}
	
	cout << m << endl;
	
	return 0;
}
