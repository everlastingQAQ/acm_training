#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	int local, luogu;
	local = 5 * n;
	luogu = 11 + 3 * n;
	if (local < luogu) {
		printf("Local");
	}else {
		printf("Luogu");
	}
	return 0;
}
