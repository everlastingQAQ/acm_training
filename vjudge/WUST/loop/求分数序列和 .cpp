#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	double sum = 0;
	double p = 1;
	double q = 2;
	for (int i = 0; i < n; i++) {
		sum += q / p;
		int t = q;
		q += p;
		p = t;
	}
	
	printf("%.4f", sum);
	
	return 0;
}
