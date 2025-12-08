#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a[6] = {0};
	int eat = 0;
	
	for (int i = 1; i <= 5; i++) {
		cin >> a[i];
	}
	
	int t = a[1] / 3;
	eat += a[1] - t * 3;
	a[5] += t;
	a[2] += t;
	a[1] = t;
	
	for (int i = 2; i <= 4; i++) {
		int m = a[i] / 3;
		eat += a[i] - m * 3;
		a[i + 1] += m;
		a[i - 1] += m;
		a[i] = m;
	}
	
	int n = a[5] / 3;
	eat += a[5] - n * 3;
	a[1] += n;
	a[4] += n;
	a[5] = n;
	
	for (int i = 1; i <= 5; i++) {
		cout << a[i] << ' ';
	}
	cout << endl << eat << endl;
	
	return 0;
}
