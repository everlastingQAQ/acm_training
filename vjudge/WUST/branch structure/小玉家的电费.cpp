#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double n;
	cin >> n;
	double rs = 0;
	if (n <= 150) {
		rs = n * 0.4463;
	}else if (n > 150 && n <= 400) {
		rs = 150 * 0.4463 + (n - 150) * 0.4663;
	}else if (n > 400) {
		rs = 150 * 0.4463 + (400 - 150) * 0.4663 + (n - 400) * 0.5663;
	}
	printf("%.1f", rs);
	return 0;
}
