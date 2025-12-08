#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, x;
	cin >> n >> x;
	
	char c = '0' + x;
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		for (size_t j = 0; j < s.size(); j++) {
			if (s[j] == c) {
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
