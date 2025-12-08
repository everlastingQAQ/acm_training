#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	vector <int> v;
	int n;
	while (cin >> n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			sum += a;
		}
		v.push_back(sum);
	}
	
	for (auto sums : v) {
		cout << sums << endl;
	}
	
	return 0;
}
