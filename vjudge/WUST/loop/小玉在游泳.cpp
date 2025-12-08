#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double s;
	cin >> s;
	
	double l = 2;
	int cnt = 0;
	double sum = 0;
	while (sum < s) {
		sum += l;
		l *= 0.98;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
