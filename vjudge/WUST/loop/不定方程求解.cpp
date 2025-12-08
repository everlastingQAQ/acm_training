#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b, c;
	cin >> a >> b >> c;
	
	int cnt = 0;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (i * a + j * b == c) {
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
