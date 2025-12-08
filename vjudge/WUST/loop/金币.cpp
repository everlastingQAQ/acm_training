#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int k;
	cin >> k;
	
	int sum = 0;
	int day = 0;
	int i = 1;
	while (day <= k) {
		if (day + i > k) {
			sum += (k - day) * i;
			break;
		}
		sum += i * i;
		day += i;
		i++;
	}
	cout << sum << endl;
	return 0;
}
