#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	vector <int> sums;
	
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		sums.push_back(a + b);
	}
	
	for (auto sum : sums) {
		cout << sum << endl;
	}
	
	return 0;
	
}
