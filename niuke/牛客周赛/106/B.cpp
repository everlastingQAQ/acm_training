#include <bits/stdc++.h>
using namespace std;

long long reverse_number (long long n)
{
	long long rs = 0;
	while (n != 0) {
		rs = rs * 10 + n % 10;
		n /= 10; 
	}
	return rs;
}

int main ()
{
	int t;
	cin >> t;
	vector <long long> rs;
	vector <long long> cnts;
	
	for (int i = 0; i < t; i++) {
		long long n, k;
		cin >> n >> k;
		long long cnt = 0;
		bool found = 0;
		for (int j = 0; j < k; j++) {
			long long m = reverse_number(n) + n;
			cnt++;
			long long b = m;
			if (b == reverse_number(m)) {
				n = m;
				found = 1;
				break;
			}else {
				n = m;
			}
		}
		if (n != reverse_number(n) && !found) cnt = -1;
		rs.push_back(n);
		cnts.push_back(cnt);
	}
	
	for (int i = 0; i < t; i++) {
		cout << rs[i] << " " << cnts[i] << endl;
	}
	
	return 0;
	
}
