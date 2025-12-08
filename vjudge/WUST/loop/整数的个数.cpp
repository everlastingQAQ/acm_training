#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int k;
	cin >> k;
	
	int cnt_1 = 0;
	int cnt_5 = 0;
	int cnt_10 = 0;
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		if (n == 1) cnt_1++;
		if (n == 5) cnt_5++;
		if (n == 10) cnt_10++;
	}
	cout << cnt_1 << endl << cnt_5 << endl << cnt_10 << endl;
	return 0;
}
