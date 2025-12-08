#include <bits/stdc++.h>
using namespace std;

int main ()
{
	double x;
	int n;
	cin >> x >> n;
	double res = 1;
	for (int i = 1; i <= n; i++) {
		res += pow(x, i);
	}
	printf("%.2f", res);
	return 0;
}
