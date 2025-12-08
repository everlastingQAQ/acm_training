#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b, c;
	cin >> a >> b >> c;
	int cnt = 0;
	if (a < 60) cnt++;
	if (b < 60) cnt++;
	if (c < 60) cnt++;
	if (cnt == 1) cout << 1;
	if (cnt != 1) cout << 0;
	return 0;
}
