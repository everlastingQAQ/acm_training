#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int k;
			cin >> k;
			v[i] += k; 
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}
	
	return 0;
}
