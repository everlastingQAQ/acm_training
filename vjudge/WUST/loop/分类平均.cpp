#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, k;
	cin >> n >> k;
	
	int sum1 = 0;
	int cnt1 = 0;
	int sum2 = 0;
	int cnt2 = 0;
	
	for (int i = 1; i <= n; i++) {
		if (i % k == 0) {
			sum1 += i;
			cnt1++;
		}else {
			sum2 += i;
			cnt2++;
		}
	}
	
	double res1 = 1.0 * sum1 / cnt1;
	double res2 = 1.0 * sum2 / cnt2;
	
	printf("%.1f %.1f", res1, res2);
	
	return 0;
}
