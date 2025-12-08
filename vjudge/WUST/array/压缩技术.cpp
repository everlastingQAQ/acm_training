#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int a[400010];
	int t = -1;
	int j = 0;
	int cnt = 0;
	while (cin >> t && j < n * n) {
		
		if (cnt % 2 == 0) {
			for (int i = j; i < t + j; i++) {
				a[i] = 0;
			}
		}else {
			for (int i = j; i < t + j; i++) {
				a[i] = 1;
			}
		}
		j += t;
		cnt++;
	}
	
	for (int i = 0; i < n * n; i++) {
		cout << a[i];
		if ((i + 1) % n == 0 && i != 0 && i != n * n - 1) {
			cout << endl;
		}
	}
	
	return 0;
	
}
