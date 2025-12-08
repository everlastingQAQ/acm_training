#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	vector <int> v;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	int m;
	cin >> m;
	cout << count (v.begin(), v.end(), m);
	return 0;
}
