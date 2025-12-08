#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	int a[n] = {};
	cin >> a[0];
	int rs = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i + 1 < n) {
			cin >> a[i + 1];
		}
		if (a[i + 1] - a[i] == 1) {
			cnt++;
		}else {
			if (cnt + 1 > rs) {
				rs = cnt + 1;
			}
			cnt = 0;
		}
	}
	cout << rs;
	return 0;
}
