#include <bits/stdc++.h>
using namespace std;
const int M = 40004;

int main ()
{
	char s[M];
	int i = 0;
	
	int a[M];
	int j = 1;
	
	while (cin >> s[i]) {
		i++;
	}
	
	if (s[0] == '1') {
		a[j++] = 0;
	}
	
	int cnt = 1;
	for (int k = 1; k < i; k++) {
		if (s[k] == s[k - 1]) {
			cnt++;
		}else {
			a[j++] = cnt;
			cnt = 1;
		}
	}
	a[j++] = cnt;
	a[0] = sqrt(i);
	
	for (int k = 0; k < j; k++) {
		cout << a[k] << ' ';
	}
	return 0;
}
