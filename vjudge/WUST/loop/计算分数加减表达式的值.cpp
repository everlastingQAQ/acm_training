#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double sum = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t = i;
		if (t % 2 == 0) {
			t *= -1;
		}
		sum += 1.0 / t;
	}
	printf("%.4f", sum);
	return 0;
}
