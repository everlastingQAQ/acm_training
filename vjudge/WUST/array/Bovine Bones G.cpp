#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	
	int max = s1 + s2 + s3;
	int a[max + 1] = {};
	
	int sum = 0;
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				sum = i + j + k;
				for (int l = 3; l <= max; l++) {
					if (sum == l) {
						a[l]++;
						break;
					}
				}
			}
		}
	}
	
	int max_sum = max;
	for (int i = max - 1; i >= 3; i--) {
		if (a[i] >= a[max_sum]) {
			max_sum = i;
		}
	}
	
	cout << max_sum << endl;
	
	return 0;
}
