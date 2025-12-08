#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int l, r;
	cin >> l >> r;
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		string s = to_string(i);
		cnt += count (s.begin(), s.end(), '2');
	}
	cout << cnt;
	return 0;
}
