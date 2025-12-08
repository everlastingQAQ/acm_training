#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	if (n % 3 == 0 && n % 5 == 0) {
		printf("YES");
	}else {
		printf("NO");
	}
	return 0;
}
