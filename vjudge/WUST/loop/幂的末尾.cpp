#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b;
	cin >> a >> b;
	
	int t = 1;
	for (int i = 0; i < b; i++) {
		t *= a;
		t %= 1000;
	}
	printf("%03d", t);
	return 0;
}
