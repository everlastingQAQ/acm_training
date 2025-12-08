#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int t = n;
	vector <int> a;
	int i = 0;
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}else {
			n = n * 3 + 1;
		}
		a.push_back(n);
	}
	
	for (int i = a.size() - 1; i >= 0; i--) {
		cout << a[i] << ' ';
	}
	
	cout << t;
	
	return 0;
	
}
