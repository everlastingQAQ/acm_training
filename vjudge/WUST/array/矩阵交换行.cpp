#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n = 5;
	int s[n][n];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	
	int a, b;
	cin >> a >> b;
	
	for (int i = 0; i < n; i++) {
		swap(s[a - 1][i], s[b - 1][i]);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << s[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
