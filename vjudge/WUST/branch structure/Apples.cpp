#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int x;
	cin >> x;
	if (x > 1) {
		printf("Today, I ate %d apples.", x);
	}if (x == 1 || x == 0) {
		printf("Today, I ate %d apple.", x);
	}
	return 0;
}
