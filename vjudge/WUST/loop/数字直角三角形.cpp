#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int t = n;
	int number = 1;
	for (int i = 0; i < n; i++) {
		for (int j = t; j > 0; j--) {
			printf("%02d", number);
			number++;
		}
		printf("\n");
		t--;
	}
	
	return 0;
}
