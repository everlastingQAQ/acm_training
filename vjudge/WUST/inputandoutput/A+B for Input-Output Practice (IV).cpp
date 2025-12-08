#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	vector <int> sums;	
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		int t = 0;
		for (int i = 0; i < n; i++) {
			int m;
			cin >> m;
			t += m;
		}
		sums.push_back(t);
	}
	
	for (auto sum : sums) {
		cout << sum << endl;
	}
	
	return 0;
}
