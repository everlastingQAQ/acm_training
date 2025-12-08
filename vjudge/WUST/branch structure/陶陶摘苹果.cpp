#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a[10] = {};
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	
	int n;
	cin >> n;
	n += 30;
	
	int cnt = 0;
	for (int i = 0 ; i < 10; i++) {
		if (n >= a[i]) {
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
	
}
