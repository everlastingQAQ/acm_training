#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	int a[3][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> a[i][j];
		}
	}
	int cost[3] = {};
	for (int i = 0; i < 3; i++) {
		cost[i] = ceil(1.0 * n / a[i][0]) * a[i][1];
	}
	int min = cost[0];
	for (int i = 1; i < 3; i++) {
		if (cost[i] < min) {
			min = cost[i];
		}
	}
	cout << min;
	return 0;
}
