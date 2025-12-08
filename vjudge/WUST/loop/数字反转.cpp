#include <bits/stdc++.h>
using namespace std;

int reverse (int n) //正负数通用
{
	bool mask = 0;
	int res = 0;
	if (n < 0) {
		n = -n;
		mask = 1;
	}
	while (n > 0) {
		res += n % 10;
		n /= 10;
		if (n == 0) break;
		res *= 10;
	}
	if (mask) {
		res = -res;
	}
	return res;
}

int main ()
{
	int n;
	cin >> n;
	cout << reverse(n) << endl;
	return 0;
}
