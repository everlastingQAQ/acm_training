#include <bits/stdc++.h>
using namespace std;
const int M = 2000002;

int main ()
{
	int n;
	cin >> n;
	
	bool light[M] = {};
	double a;
	int t;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> t;
		for (int j = 1; j <= t; j++) {
			light[(int) (a * j)] = !light[(int) (a * j)];
		}
	}
	
	for (int i = 1; i < M; i++) {
		if (light[i] == true) {
			cout << i;
			return 0;
		}
	}
	return 0;
}
