#include <bits/stdc++.h>
using namespace std;

int main ()
{
	long long m;
	int k;
	cin >> m >> k;
	
	int cnt = 0;
	long long t;
	while (m > 0) {
		t = m % 10;
		if (t == 3) cnt++;
		m /= 10;
	}
	
	if (cnt == k) cout << "YES"<< endl;
	if (cnt != k) cout << "NO"<< endl;
	
	return 0;
	
}
